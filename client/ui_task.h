/********************************************************************************
** Form generated from reading UI file 'task.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task
{
public:
    QPlainTextEdit *plainTextEditAnswer;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonGetTask;
    QComboBox *comboBoxCategories;
    QLabel *labelTask;
    QPlainTextEdit *plainTextEditVariant;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Task)
    {
        if (Task->objectName().isEmpty())
            Task->setObjectName("Task");
        Task->resize(449, 420);
        Task->setLayoutDirection(Qt::RightToLeft);
        plainTextEditAnswer = new QPlainTextEdit(Task);
        plainTextEditAnswer->setObjectName("plainTextEditAnswer");
        plainTextEditAnswer->setGeometry(QRect(10, 260, 431, 126));
        plainTextEditAnswer->setLayoutDirection(Qt::LeftToRight);
        plainTextEditAnswer->setLineWrapMode(QPlainTextEdit::NoWrap);
        horizontalLayoutWidget = new QWidget(Task);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 431, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonGetTask = new QPushButton(horizontalLayoutWidget);
        pushButtonGetTask->setObjectName("pushButtonGetTask");
        pushButtonGetTask->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(pushButtonGetTask);

        comboBoxCategories = new QComboBox(horizontalLayoutWidget);
        comboBoxCategories->setObjectName("comboBoxCategories");
        comboBoxCategories->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(comboBoxCategories);

        labelTask = new QLabel(Task);
        labelTask->setObjectName("labelTask");
        labelTask->setGeometry(QRect(10, 40, 431, 41));
        labelTask->setLayoutDirection(Qt::LeftToRight);
        labelTask->setAutoFillBackground(true);
        plainTextEditVariant = new QPlainTextEdit(Task);
        plainTextEditVariant->setObjectName("plainTextEditVariant");
        plainTextEditVariant->setGeometry(QRect(10, 100, 431, 126));
        plainTextEditVariant->setLayoutDirection(Qt::LeftToRight);
        plainTextEditVariant->setLineWrapMode(QPlainTextEdit::NoWrap);
        plainTextEditVariant->setReadOnly(true);
        label = new QLabel(Task);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 240, 32, 16));
        buttonBox = new QDialogButtonBox(Task);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(280, 390, 171, 22));
        buttonBox->setLayoutDirection(Qt::RightToLeft);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Task);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Task, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Task, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Task);
    } // setupUi

    void retranslateUi(QDialog *Task)
    {
        Task->setWindowTitle(QCoreApplication::translate("Task", "Dialog", nullptr));
        pushButtonGetTask->setText(QCoreApplication::translate("Task", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\320\275\320\270\320\265", nullptr));
        labelTask->setText(QString());
        label->setText(QCoreApplication::translate("Task", "\320\236\321\202\320\262\320\265\321\202:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Task: public Ui_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
