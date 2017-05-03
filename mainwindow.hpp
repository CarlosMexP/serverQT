#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "tcpserver.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void log(const QString &msg);

    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

    void on_pushButtonQuit_clicked();

    void on_pushButtonClear_clicked();


    void on_radioButtonHex_clicked();

    void on_radioButtonText_clicked();

private:
    Ui::MainWindow *ui;

    TcpServer _server;
};

#endif // MAINWINDOW_HPP
