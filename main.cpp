#include "mainwindow.hpp"
#include <QApplication>

#include <QSqlDatabase>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);
    MainWindow w;
/*
    QSqlDatabase db(QSqlDatabase::addDatabase("QSQLITE"));
    QString databasePath;

    databasePath = QFileDialog::getOpenFileName(NULL, "choose databse",QDir::currentPath() + "/../emuladorPCA/db_pca.sqlite",
                                                "SQLite database (*sqlite)");

    if(!databasePath.isEmpty())
    {
        db.setDatabaseName(databasePath);
        if(db.open())
        {
            w.show();
            return a.exec();
        }
    }

    QMessageBox::critical(NULL, "Emulador PCA", "database not open.");
    */


    w.show();
    return a.exec();

    return 0;
}
