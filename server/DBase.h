#ifndef DBASE_H
#define DBASE_H

#include <QSqlDatabase>

class DBase;

class DBase
{
protected:
    QSqlDatabase dbInstance;

    DBase(const DBase &) = delete;
    DBase &operator=(const DBase &) = delete;

protected:
    DBase();
    ~DBase();

public:
    static DBase *getInstance();
    bool isConnected() const;
    QString doSQLQuery(const QString &stringQuery);
};

#endif // DBASE_H
