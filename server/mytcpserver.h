#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <map>
#include <iostream>
#include <string>
using std::map;
using std::string;

class MyTcpServer : public QObject
{
    Q_OBJECT

public:
    static MyTcpServer* getInstance();

    ~MyTcpServer();

    int getServerStatus() const; // Публичный метод для получения статуса сервера

private:
    explicit MyTcpServer(QObject *parent = nullptr);

    QTcpServer* mTcpServer;
    QMap<int, QTcpSocket*> mTcpSocket;
    int server_status;

    static MyTcpServer* instance;

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();
};

#endif // MYTCPSERVER_H
