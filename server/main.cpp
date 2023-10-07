#include <QCoreApplication>
#include "mytcpserver.h"
#include "DBase.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyTcpServer* server = MyTcpServer::getInstance();

    // Проверяем статус сервера
    if (server->getServerStatus() == 1) {
        qDebug() << "Server is running.";
    } else {
        qDebug() << "Server failed to start.";
    }

    // Проверяем, успешно ли инициализирована база данных
    if (DBase::getInstance()->isConnected()) {
        qDebug() << "Database connected.";
    } else {
        qDebug() << "Database connection failed.";
    }

    return a.exec();
}
