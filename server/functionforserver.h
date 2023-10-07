#ifndef FUNCTIOFORSERVER_H
#define FUNCTIOFORSERVER_H

#include <QStringList>
#include <QString>
#include <QMap>
#include <QDebug>
#include <iostream>
#include <vector>
#include <queue>
//#include <QMainWindow>

QByteArray parsing (QString data_from_client);

QByteArray auth(QString log, QString pass);
QByteArray reg(QString log, QString pass);
QByteArray get_stat(QString log);

#endif // FUNCTIOFORSERVER_H
