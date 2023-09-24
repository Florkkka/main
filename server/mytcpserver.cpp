#include "mytcpserver.h"
#include "functionforserver.h"
#include <QCoreApplication>
MyTcpServer::~MyTcpServer()
{
    for (auto Socket : mTcpSocket) {
        Socket.second->close();
    }
    mTcpServer->close();
    server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        QTcpSocket* socket = mTcpServer->nextPendingConnection();
        int client_desc = socket->socketDescriptor();
        mTcpSocket[client_desc] = socket;
        socket->write("Server is working for many clients!\n");
        std::string str = std::to_string(client_desc);
        const char *c = str.c_str();
        socket->write("Your id_desctiption -> ");
        socket->write(c);
        socket->write("\n");
        connect(socket, &QTcpSocket::readyRead,
                this, &MyTcpServer::slotServerRead);
        connect(socket, &QTcpSocket::disconnected,
                this, &MyTcpServer::slotClientDisconnected);
    }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket* socket = (QTcpSocket*)sender();
    int desc = socket->socketDescriptor();
    QString res = "";
    while(mTcpSocket[desc]->bytesAvailable()>0)
    {
        QByteArray array =socket->readAll();
        res.append(array);
    }
    socket->write(parsing(res.toUtf8()));
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* socket = (QTcpSocket*)sender();
    int desc = socket->socketDescriptor();
    socket->close();
    mTcpSocket.erase(desc);
}

