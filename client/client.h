#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>

class Client {
private:
    static Client* instance;
    Client();

public:
    static Client* getInstance();
    void connectToServer();
    void sendData(const std::string& data);
    void disconnectFromServer();
};

#endif // CLIENT_H
