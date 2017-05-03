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
    void setRxTextFormat();  // Format of the message for the signal "log"
    void setRxHexFormat();   // Format of the message for the signal "log"
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
    bool rxTextFormat; // Format of the message for the signal "log"
private slots:
    void connectionEstablished();
    void serverError(QAbstractSocket::SocketError socketError);
    void socketError(QAbstractSocket::SocketError socketError);
    void requestReceived();
    void disconnectClient();

};

#endif // TCPSERVER_HPP
