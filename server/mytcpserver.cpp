#include "mytcpserver.h"
#include "functionforserver.h" // Правильное включение функции parsing

MyTcpServer* MyTcpServer::instance = nullptr;

MyTcpServer* MyTcpServer::getInstance()
{
    if (!instance)
    {
        instance = new MyTcpServer;
    }
    return instance;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if (!mTcpServer->listen(QHostAddress::Any, 33333)) {
        server_status = 0; // Устанавливаем статус сервера в 0, если он не запустился
        qDebug() << "Server is not started";
    } else {
        server_status = 1;
        qDebug() << "Server is started";
    }
}

MyTcpServer::~MyTcpServer()
{
    for (auto it = mTcpSocket.begin(); it != mTcpSocket.end(); ++it) {
        it.value()->close();
        delete it.value(); // Освобождаем память
    }
    mTcpServer->close();
    server_status = 0;
}

int MyTcpServer::getServerStatus() const
{
    return server_status;
}

void MyTcpServer::slotNewConnection()
{
    if (server_status == 1) {
        QTcpSocket* socket = mTcpServer->nextPendingConnection();
        int client_desc = socket->socketDescriptor();
        mTcpSocket[client_desc] = socket;
        socket->write("Server is working for many clients!\n");
        std::string str = std::to_string(client_desc);
        const char *c = str.c_str();
        socket->write("Your id_description -> ");
        socket->write(c);
        socket->write("\n");
        connect(socket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
        connect(socket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
    }
}

void MyTcpServer::slotServerRead()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket)
        return;

    int desc = socket->socketDescriptor();
    QString res = "";
    while (socket->bytesAvailable() > 0)
    {
        QByteArray array = socket->readAll();
        res.append(array);
    }

    // Вызов функции parsing
    QByteArray result = parsing(res.toUtf8());

    socket->write(result);
}

void MyTcpServer::slotClientDisconnected()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket)
        return;

    int desc = socket->socketDescriptor();
    socket->close();
    mTcpSocket.remove(desc);
}
