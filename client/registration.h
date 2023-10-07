#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QString>

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Registration *ui;

    bool isLogExists(const QString& log);
};

#endif // REGISTRATION_H
