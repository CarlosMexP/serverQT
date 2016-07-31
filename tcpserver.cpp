#include "tcpserver.hpp"

#include <QSqlDatabase>
#include <QSqlQuery>

#include "compcadefs.h"
#include "crc.h"
#include "util.hpp"

TcpServer::TcpServer(QObject *parent) :
    QObject(parent),
    _server(new QTcpServer()),
    _socket(NULL),
    _port(0)
{
    _connectionTimer.setInterval(10000);

    connect(_server, SIGNAL(newConnection()), this, SLOT(connectionEstablished()));
    connect(&_connectionTimer, SIGNAL(timeout()), this, SLOT(diconnectClient()));
}

TcpServer::~TcpServer()
{
    delete _server;
}

void TcpServer::setPort(uint port)
{
    if(_server->isListening())
    {
        _server->close();
        _port = port;
        _server->listen(QHostAddress::Any, _port);
    }
    else
    {
        _port = port;
    }
}

int TcpServer::port()
{
    return _port;
}

bool TcpServer::open()
{
    return _server->listen(QHostAddress::Any, _port);
}

void TcpServer::close()
{
    _server->close();
}

QByteArray TcpServer::buildDeviceFrame(uchar commandId, QByteArray data)
{
    QByteArray deviceFrame;
    int deviceFrameSize;
    int sizeInnerFrame;

    if (data.isNull())
    {
        deviceFrameSize = 6;
    }
    else
    {
        deviceFrameSize = 6 + data.size();
    }
    sizeInnerFrame = deviceFrameSize - 2;

    deviceFrame.resize(sizeInnerFrame);
    deviceFrame[0] = 0xFE;
    deviceFrame[1] = sizeInnerFrame;
    deviceFrame[2] = commandId;
    deviceFrame[deviceFrameSize - 1] = 0xEF;
    if (!data.isNull())
    {
        for (int i = 0; i < data.size(); i++)
        {
            deviceFrame[i + 3] = data.at(i);
        }
    }
    inserta_CRC((uchar*)&deviceFrame.data()[1], sizeInnerFrame - 2);

    emit log("Frame to be sent: " + toString(deviceFrame));
    return deviceFrame;
}

uchar TcpServer::addUser(const uchar* data)
{
    QSqlDatabase db(QSqlDatabase::database());
    QSqlQuery query(db);

    QString uid;
    int hrn;
    QDate expiration;
    uchar rsp;

    int numUsers;

    uid += QString::number(data[0], 16).rightJustified(2, '0').toUpper();
    uid += QString::number(data[1], 16).rightJustified(2, '0').toUpper();
    uid += QString::number(data[2], 16).rightJustified(2, '0').toUpper();
    uid += QString::number(data[3], 16).rightJustified(2, '0').toUpper();
    hrn = data[4];
    expiration.setDate((data[7] >> 4) * 10 + (data[7] & 0x0F) + 2000,
            (data[6] >> 4) * 10 + (data[6] & 0x0F),
            (data[5] >> 4) * 10 + (data[5] & 0x0F));

    query.exec("SELECT COUNT(*) FROM mdu");
    query.first();
    numUsers = query.value(0).toInt();

    if(numUsers < 2000)
    {
        query.exec("SELECT * FROM mdu WHERE uid = '" + uid + "'");
        if(query.first())
        {
            rsp = ComPcaDefs::RSP_AGREGAR_USUARIO_YA_EXISTE_EN_MEMORIA;
            emit log("User already exists");
        }
        else
        {
            query.prepare("INSERT INTO mdu (uid, hrn, expiration) VALUES(?, ?, ?)");
            query.bindValue(0, uid);
            query.bindValue(1, hrn);
            query.bindValue(2, expiration);

            if(query.exec())
            {
                rsp = ComPcaDefs::RSP_AGREGAR_USUARIO;
                emit log("User inserted");
            }
            else
            {
                rsp = ComPcaDefs::RSP_AGREGAR_USUARIO_YA_EXISTE_EN_MEMORIA;
                emit log("DB ERROR");
            }
        }
    }
    else
    {
        rsp = ComPcaDefs::RSP_AGREGAR_USUARIO_MEMORIA_LLENA;
        emit log("Memory Full");
    }

    return rsp;
}

void TcpServer::connectionEstablished()
{
    emit log("Connection established with host");

    _connectionTimer.start();
    _socket = _server->nextPendingConnection();
    connect(_socket, SIGNAL(readyRead()), this, SLOT(requestReceived()));
}

void TcpServer::serverError(QAbstractSocket::SocketError socketError)
{
    emit log(_server->errorString());
    switch(socketError)
    {
        default:
            break;
    }
}

void TcpServer::socketError(QAbstractSocket::SocketError socketError)
{
    emit log(_socket->errorString());
    switch(socketError)
    {
        default:
            break;
    }
}

void TcpServer::requestReceived()
{
    QByteArray receiverBuffer;
    QByteArray data;

    uchar frameBegin;
    uint ld;
    uchar cmd;
    uchar frameEnd;

    QString strAux;
    uchar rsp;

    _connectionTimer.stop();

    receivierBuffer = _socket->readAll();
    emit log("Frame Received: " + toString(receivierBuffer));
    if(!verifica_CRC((uchar*) &receivierBuffer.data()[1], receivierBuffer.size() - 2))
    {
        emit log("CRC ERROR");
        return;
    }

    frameBegin = receivierBuffer.at(0);
    frameEnd = receivierBuffer.at(receivierBuffer.size() - 1);
    if(frameBegin != 0xFE || frameEnd != 0xEF)
    {
        emit log("Frame begin or end couldn't found");
        return;
    }

    cmd = receivierBuffer[2];

    emit log("COMMAND: " + QString::number(cmd, 16).rightJustified(2, '0'));
    _bytesWritten = false;
    switch(cmd)
    {
    case ComPcaDefs::CMD_CONECTAR:
        _socket->write(this->buildDeviceFrame(ComPcaDefs::RSP_CONECTAR, data));
        break;
    case ComPcaDefs::CMD_LEER_HORA_DIA_PCA:
        strAux = QDateTime::currentDateTime().toString("hhmmssddMMyy");
        emit log("Current Date Time: " + strAux);
        data.resize(7);
        data[0] = strAux.mid(0, 2).toUInt(0, 16);
        data[1] = strAux.mid(2, 2).toUInt(0, 16);
        data[2] = strAux.mid(4, 2).toUInt(0, 16);
        data[3] = QDateTime::currentDateTime().date().dayOfWeek();
        data[4] = strAux.mid(6, 2).toUInt(0, 16);
        data[5] = strAux.mid(8, 2).toUInt(0, 16);
        data[6] = strAux.mid(10, 2).toUInt(0, 16);
        _socket->write(this->buildDeviceFrame(ComPcaDefs::RSP_LEER_HORA_DIA_PCA, data));
        break;
    case ComPcaDefs::CMD_AGREGAR_USUARIO:
        rsp = addUser((uchar*) &receivierBuffer.constData()[3]);
        _socket->write(this->buildDeviceFrame(rsp, data));
        break;
    default:
        break;
    }

    _connectionTimer.start();
}

void TcpServer::diconnectClient()
{
    _socket->abort();
    //delete _socket;
}













