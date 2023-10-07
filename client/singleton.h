#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton {
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    // Другие методы и переменные экземпляра класса

private:
    Singleton() {} // Приватный конструктор, чтобы предотвратить создание экземпляров класса
    static Singleton* instance; // Указатель на единственный экземпляр класса
};

#endif // SINGLETON_H
