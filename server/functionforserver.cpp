#include "functionforserver.h"
#include <QDebug>
#include "DBase.h"
QByteArray reg(QString log, QString pass)
{

    QString query = QString("INSERT INTO Users (log, pass) VALUES(\"%1\", \"%2\")").arg(log, pass);
    DBase::getInstance()->doSQLQuery(query);
    QString s = DBase::getInstance()->doSQLQuery("SELECT * from Users where log = \"" + log+"\"");
    if (s.size()>0) {
        return "reg+";
    } else {
        return "reg-";
    }
}

QByteArray auth(QString log,QString pass)
{
    QString query = QString("SELECT * FROM Users WHERE (log, pass) = (\"" + log+"\", \"" + pass+"\")");


    if (DBase::getInstance()->doSQLQuery(query).size()>0){  // Если найдено больше нуля записей с заданным именем пользователя,
        return "auth+";
        DBase::getInstance()->doSQLQuery("UPDATE Users SET in_sys = 1 WHERE log = \"" + log+"\"");         // дополнительный столбец  in_sys для обозначения пользователя в системе
    }
    else                                                                     // Иначе пользователь с заданным именем не найден в базе данных.
        return "auth-";
}

QByteArray get_stat(QString log){
   QString query = ("SELECT task1, task2, task3, task4 FROM users WHERE log = \"" + log+"\"");
   qDebug()<<query;
   QString response = "";
    if (DBase::getInstance()->doSQLQuery(query).size()>0){
        response = DBase::getInstance()->doSQLQuery(query);

        return response.toUtf8();
    }
    else
        return "stat-";
}

QByteArray task1(){
     return "task1";
}

QByteArray task2(){
     return "task2";
}

QByteArray task3(){
     return "task3";
}

QByteArray task4(){
     return "task4";
}

QByteArray parsing (QString data_from_client)

{
     qDebug()<<data_from_client;
    if(data_from_client.contains('&'))
    {
        data_from_client = data_from_client.replace(QString("\r\n"), QString(""));
        QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
        QString log, pass;

        if(data_from_client_list.front() == "reg")
        {
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            data_from_client_list.pop_front();
            pass = data_from_client_list.front();
            return reg(log, pass);
        }
        if(data_from_client_list.front() == "auth")
        {
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            data_from_client_list.pop_front();
            pass = data_from_client_list.front();
            return auth(log, pass);
        }
        if(data_from_client_list.front() == "stat")
        {
            data_from_client_list.pop_front();
            log = data_from_client_list.front();
            data_from_client_list.pop_front();
            return get_stat(log);
        }
        if(data_from_client_list.front() == "task")
        {
            data_from_client_list.pop_front();
            QString type = data_from_client_list.front();
            data_from_client_list.pop_front();
            if (type=="1") {return "asd";}
            else if  (type=="2") {return task2();}
            else if  (type=="3") {return task3();}
            else if  (type=="4") {return task4();}

        }
        if(data_from_client_list.front() == "names")
        {return "task1&task2&task3&task4";}

    } else
    {
        return data_from_client.toUtf8();
    }
}
