#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H

#include <iostream>
#include <string>

class SingletonClient
{
public:
    static SingletonClient* getInstance();

    void connectToServer();
    void sendData(const std::string& data);
    void disconnectFromServer();

private:
    SingletonClient(); // Приватный конструктор, чтобы предотвратить создание экземпляров класса.
    static SingletonClient* instance;
};

#endif // SINGLETONCLIENT_H
