#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H

#include <QTcpSocket>

class SingletonClient : public QObject
{
    Q_OBJECT

private:
    explicit SingletonClient(QObject* parent = nullptr);

public:
    static SingletonClient* getInstance();

public slots:
    void connectToServer(const QString& host, int port);
    void sendData(const QByteArray& data);

private slots:
    void onNewDataReceived(const QByteArray& data);
    void onConnected();
    void onDisconnected();

private:
    QTcpSocket* socket;
    static SingletonClient* instance;
};

#endif // SINGLETONCLIENT_H
