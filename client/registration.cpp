#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "socket.h"

Registration::Registration(QWidget *parent) : // Вызов окна регистрации
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    ui->reg_pas->setEchoMode(QLineEdit::Password);
    ui->reg_pas_repeat->setEchoMode(QLineEdit::Password);
}

Registration::~Registration() // Деструктор, срабатывающий при закрытии UI регистрации
{
    delete ui;
}

void Registration::on_pushButton_clicked() // Проверка соответствия полей login password1 password2 при нажатии кнопки "Подтвердить"
{
    QString reg_log = ui->mail->text();
    QString reg_pas_1 = ui->reg_pas->text();
    QString reg_pas_2 = ui->reg_pas_repeat->text();

    if (reg_pas_1 == reg_pas_2) { // Сравнение полей password1 и password2
        qDebug("Пароли совпадают! Ожидание отправки");

        // Check if the log already exists
        if (isLogExists(reg_log)) {
            QMessageBox::warning(this, "Ошибка", "Логин уже зарегистрирован");
            return;
        }

        QString ctrl_msg = "reg&" + reg_log + "&" + reg_pas_1; // Возможность регистрации через поле ввода текста
        Socket::GetInstance()->sk.write(ctrl_msg.toUtf8());
        Socket::GetInstance()->sk.waitForReadyRead();
        QString buf = Socket::GetInstance()->sk.readAll();

        // Добавление аккаунта при успешной регистрации
        if (buf == "reg+") {
            QMessageBox::information(this, "Успешная регистрация", "Вы успешно зарегистрировались!");
            close();
        }
        else {
            QMessageBox::warning(this, "Ошибка", "Фатальная ошибка"); // Ошибка регистрации
        }
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Пароли не совпадают"); // Выводится при ошибке в воде логина/пароля
    }
}

bool Registration::isLogExists(const QString& log)
{
    // Implement your logic to check if the login already exists
    // For example, you can query a database or check in a list of registered logins

    // Replace this with your own implementation
    QStringList registeredLogins = {"user1", "user2", "user3"};
    return registeredLogins.contains(log);
}
