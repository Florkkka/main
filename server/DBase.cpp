#include "DBase.h"

#include <QDebug>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

#define _DB_NAME "DataBase"

DBase::DBase()
{
    //this->dbInstance = QSqlDatabase::addDatabase("QSQLITE");
    //this->dbInstance.setDatabaseName(_DB_NAME);
    if (!this->dbInstance.open()) {
        qDebug() << this->dbInstance.lastError().text();
    };
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/server/DB1.db");
    if (db.open())
    {
        qDebug("connected to database");
    }
    else
    {
        qDebug("Error occured in connection to database");
    }
}

DBase::~DBase() {
    this->dbInstance.close();
}


QString DBase::doSQLQuery(QString stringQuery)
{
        QSqlQuery sqlQuery(db);
        if (!sqlQuery.exec(stringQuery)) {
            qDebug() << "Failed to execute query: " << sqlQuery.lastError().text();
            return "";
        }
        QString result = "";
        while (sqlQuery.next()) {
            result = sqlQuery.value(0).toString();
        }
        return result;
}
BaseDestroyer DBase::destroyer;
DBase* DBase::pInstance = nullptr;
QSqlDatabase DBase::dbInstance;
