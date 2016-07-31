#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButtonStop->setHidden(true);
    connect(&_server, SIGNAL(log(QString)), this, SLOT(log(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::log(const QString &msg)
{
    ui->listWidget->addItem(msg);
    ui->listWidget->scrollToBottom();
}

void MainWindow::on_pushButtonStart_clicked()
{
    _server.setPort(ui->spinBox->value());
    if(_server.open())
    {
        log("Connection opened");
        ui->pushButtonStart->setHidden(true);
        ui->pushButtonStop->setHidden(false);
    }
    else
    {
        log("port cannot binds, try another");
    }
}

void MainWindow::on_pushButtonStop_clicked()
{
    _server.close();

    ui->pushButtonStop->setHidden(true);
    ui->pushButtonStart->setHidden(false);

    log("Connection closed");
}

void MainWindow::on_pushButtonQuit_clicked()
{
    QCoreApplication::exit(0);
}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->listWidget->clear();
}
