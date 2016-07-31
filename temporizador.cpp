#include "temporizador.h"
#include <QTime>
#include <QCoreApplication>
#include <QDebug>

Temporizador::Temporizador(QObject *parent) : QObject(parent)
{

}

Temporizador::~Temporizador()
{
   // dTime = QTime::currentTime();
   // qDebug()<< "Detener timer "<< dTime.toString("hh:mm:ss.zzz");
}

void Temporizador::start(int ms)
{

    dTime = QTime::currentTime().addMSecs( ms);
    //qDebug() << "Inicia timer "<< QTime::currentTime().toString("hh:mm:ss.zzz");

    int c= 0;
    while( QTime::currentTime() < dTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 50 );
        c++;
    }

    //qDebug() << "Termina timer "<< dTime.toString("hh:mm:ss.zzz");
}

void Temporizador::stop()
{
    dTime = QTime::currentTime();
    //qDebug()<< "Detener timer "<< dTime.toString("hh:mm:ss.zzz");
}

