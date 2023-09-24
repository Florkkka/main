#include <QCoreApplication>
#include "mytcpserver.h"
#include "DBase.h"
#include <QSqlDatabase>


int main(int argc, char *argv[]) // Запускает все остальные файлы
{
    QCoreApplication a(argc, argv);




    MyTcpServer server;
    DBase::getInstance();

    return a.exec();
}
//main.cpp

