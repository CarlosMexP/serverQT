#ifndef TCPSERVER_HPP
#define TCPSERVER_HPP

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>

#include "temporizador.h"

class TcpServer : public QObject
{
    Q_OBJECT

public:
    TcpServer(QObject *parent = NULL);
    virtual ~TcpServer();

    void setPort(uint port);
    int port();

    bool open();
    void close();

signals:
    void log(const QString &msg);

private:
    QTcpServer *_server;
    QTcpSocket *_socket;
    uint _port;
    QTimer _connectionTimer;
    Temporizador _timer;
    bool _bytesWritten;
private slots:
    void connectionEstablished();
    void serverError(QAbstractSocket::SocketError socketError);
    void socketError(QAbstractSocket::SocketError socketError);
    void requestReceived();

    void diconnectClient();

};

#endif // TCPSERVER_HPP
