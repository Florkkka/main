#include "singletonclient.h"
#include <QHostAddress>
#include <QDebug>

SingletonClient::SingletonClient(QObject* parent)
    : QObject(parent), socket(nullptr)
{
}

SingletonClient* SingletonClient::getInstance()
{
    if (!instance)
        instance = new SingletonClient();
    return instance;
}

void SingletonClient::connectToServer(const QString& host, int port)
{
    if (socket && socket->state() != QAbstractSocket::UnconnectedState)
    {
        qDebug() << "Already connected to server.";
        return;
    }

    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::connected, this, &SingletonClient::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &SingletonClient::onDisconnected);
    connect(socket, &QTcpSocket::readyRead, this, [this]() {
        QByteArray data = socket->readAll();
        onNewDataReceived(data);
    });

    socket->connectToHost(QHostAddress(host), port);
}

void SingletonClient::sendData(const QByteArray& data)
{
    if (socket && socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(data);
        socket->flush();
    }
}

void SingletonClient::onNewDataReceived(const QByteArray& data)
{
    // Process received data here
    qDebug() << "Received data: " << data;
}

void SingletonClient::onConnected()
{
    qDebug() << "Connected to server.";
}

void SingletonClient::onDisconnected()
{
    qDebug() << "Disconnected from server.";
    socket->deleteLater();
    socket = nullptr;
}

SingletonClient* SingletonClient::instance = nullptr;
