#-------------------------------------------------
#
# Project created by QtCreator 2016-05-21T14:35:27
#
#-------------------------------------------------

QT       += core gui network sql

CONFIG +=   c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server_basic
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpserver.cpp \
    compcadefs.cpp \
    crc.cpp \
    util.cpp \
    temporizador.cpp

HEADERS  += mainwindow.hpp \
    tcpserver.hpp \
    compcadefs.h \
    crc.h \
    util.hpp \
    temporizador.h

FORMS    += mainwindow.ui
