#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H

#include <QObject>
#include <QTime>

class Temporizador : public QObject
{
    int msEspera;
    QTime dTime;
    Q_OBJECT
public:
    explicit Temporizador(QObject *parent = 0);
    ~Temporizador();
    void start(int ms);
    void stop();
signals:

public slots:
};

#endif // TEMPORIZADOR_H
