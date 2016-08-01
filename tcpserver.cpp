#include "tcpserver.hpp"

#include <QSqlDatabase>
#include <QSqlQuery>

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
    uchar cmd;
    QString strAux;
    uchar rsp;

    _connectionTimer.stop();

    receiverBuffer = _socket->readAll();
    QString rxMessage = QString::fromStdString(receiverBuffer.toStdString());
    QString txMessage = "..."+rxMessage;
    emit log("Frame Received: " + rxMessage );

    _socket->write(QByteArray::fromStdString(txMessage.toStdString()));

/*
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
        rsp = addUser((uchar*) &receiverBuffer.constData()[3]);
        _socket->write(this->buildDeviceFrame(rsp, data));
        break;
    default:
        break;
    }
*/
    _connectionTimer.start();
}

void TcpServer::diconnectClient()
{
    _socket->abort();
    //delete _socket;
}













