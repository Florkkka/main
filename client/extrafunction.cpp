#include "ui_extrafunction.h"
#include "extrafunction.h"
#include "Registration.h"
#include <QMessageBox>
#include <QString>
#include "socket.h"
#include "clientfunctions.h"

Socket *Socket::instance;

ExtraFunction::ExtraFunction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExtraFunction)
{
    ui->setupUi(this);
    isAuthorized = false;
}

ExtraFunction::~ExtraFunction()
{
    delete ui;
}

void ExtraFunction::on_pushButton_clicked() // Авторизация
{
    QString login = ui->Login->text();
    QString password = ui->Password->text(); // Сохранение пароля в переменную Password

    QString ctrl_msg = "auth&" + login + "&" + password; // Соманда для авторизации через консоль
    Socket::GetInstance()->sk.write(ctrl_msg.toUtf8());

    Socket::GetInstance()->sk.waitForReadyRead();
    QString buf = Socket::GetInstance()->sk.readAll(); // Проверка авторизации
    qDebug() <<buf;

    if (buf == "auth+")
    {
        save_setting("login", login);
        isAuthorized = true;
        close(); // Закрытие окна при успешной авторизации
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Неправильный логин или пароль"); // Вывод сообщения при ошибочном вводе
    }
}

void ExtraFunction::on_pushButton_2_clicked() // Регистрация
{
    Registration reg;
    reg.setModal(true);
    reg.exec();
}
