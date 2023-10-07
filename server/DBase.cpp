#include "DBase.h"

#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

static DBase *pInstance = nullptr;

DBase::DBase()
{
    if (!dbInstance.isValid()) {
        dbInstance = QSqlDatabase::addDatabase("QSQLITE");
        dbInstance.setDatabaseName("D:/server/DB1.db");
    }

    if (dbInstance.open()) {
        qDebug("Connected to database");
    }
    else {
        qDebug("Error occurred in connection to database");
    }
}

DBase::~DBase() {
    dbInstance.close();
}

DBase *DBase::getInstance() {
    if (!pInstance) {
        pInstance = new DBase();
    }
    return pInstance;
}

bool DBase::isConnected() const {
    return dbInstance.isOpen();
}

QString DBase::doSQLQuery(const QString &stringQuery)
{
    QSqlQuery sqlQuery(dbInstance);
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
