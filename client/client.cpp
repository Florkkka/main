#include "client.h"

Client* Client::instance = nullptr;

Client::Client() {}

Client* Client::getInstance() {
    if (instance == nullptr) {
        instance = new Client();
    }
    return instance;
}

void Client::connectToServer() {
    std::cout << "Подключение к серверу..." << std::endl;
}

void Client::sendData(const std::string& data) {
    std::cout << "Отправка данных: " << data << std::endl;
}

void Client::disconnectFromServer() {
    std::cout << "Отключение от сервера." << std::endl;
}
