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
    connect(&_connectionTimer, SIGNAL(timeout()), this, SLOT(disconnectClient()));
    rxTextFormat = true; // Default mode
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

void TcpServer::setRxTextFormat()
{
    rxTextFormat = true;
}

void TcpServer::setRxHexFormat()
{
    rxTextFormat = false; // HEX format
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
    QString strAux;
    uchar rsp;

    _connectionTimer.stop();

    receiverBuffer = _socket->readAll();
    if (rxTextFormat){
        QString rxMessage = QString::fromStdString(receiverBuffer.toStdString());
        QString txMessage = rxMessage; // A transmitir eco del mensaje
        emit log("Frame Received: " + rxMessage );
        _socket->write(QByteArray::fromStdString(txMessage.toStdString()));
    }
    else{
        /////////// MENSAJES EN HEXADECIMAL /////////////
        QByteArray txMessage = receiverBuffer; // A transmitir eco del mensaje
        emit log("Frame Received: " + txMessage.toHex() );
        _socket->write(txMessage);
    }

    _connectionTimer.start();
}

void TcpServer::disconnectClient()
{
    _socket->abort();
    //delete _socket;
}













