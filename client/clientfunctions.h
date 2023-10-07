
#ifndef CLIENTFUNCTIONS_H
#define CLIENTFUNCTIONS_H
#include <QSettings>
#include <QString>




class clientfunctions
{
public:

    clientfunctions();
};
bool save_setting(QString param_name, QString param_value);
QString load_setting(QString param_name);
bool reset_settings();

#endif // CLIENTFUNCTIONS_H
