#ifndef DBASE_H
#define DBASE_H

#include <QSqlDatabase>

class DBase;

class BaseDestroyer
{
    private:
        DBase * pInstance;
    public:
        ~BaseDestroyer() {
            delete this->pInstance;
        }
        void initialize(DBase * p) {
            this->pInstance = p;
        }
};


class DBase
{
    private:
        static DBase * pInstance;
        void initDB();
        static QSqlDatabase dbInstance;
        static BaseDestroyer destroyer;
        DBase& operator=(const DBase& );
        QSqlDatabase db;
    protected:
        DBase();
        DBase(const DBase& ) = delete;
        DBase& operator = (DBase &)=delete;
        ~DBase();
        friend class BaseDestroyer;
    public:
        static DBase* getInstance() {
            if (!pInstance)
            {
                pInstance = new DBase();
                destroyer.initialize(pInstance);
            }
            return pInstance;
        }
        static QString dbHost;
        static QString dbName;
        static QString dbUser;
        static QString dbPass;
        QString doSQLQuery(QString stringQuery);

};

#endif // DBASE_H
