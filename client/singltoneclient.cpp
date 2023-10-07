#include "singletonclient.h"

SingletonClient* SingletonClient::instance = nullptr;

SingletonClient::SingletonClient() {}

SingletonClient* SingletonClient::getInstance() {
    if (instance == nullptr) {
        instance = new SingletonClient();
    }
    return instance;
}

void SingletonClient::connectToServer() {
    std::cout << "Подключение к серверу..." << std::endl;
}

void SingletonClient::sendData(const std::string& data) {
    std::cout << "Отправка данных: " << data << std::endl;
}

void SingletonClient::disconnectFromServer() {
    std::cout << "Отключение от сервера." << std::endl;
}
