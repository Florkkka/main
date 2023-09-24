#include "clientfunctions.h"

clientfunctions::clientfunctions()
{}
 bool save_setting(QString param_name, QString param_value) {
    QSettings settings("settings.conf", QSettings::IniFormat);
    settings.beginGroup("Settings");
    settings.setValue(param_name, param_value);
    return true;
}

 QString load_setting(QString param_name) {
    QSettings settings("settings.conf", QSettings::IniFormat);
    settings.beginGroup("Settings");
    QString param = settings.value(param_name, -1 ).toString();
    return param;
}


bool reset_settings()
{
    QSettings settings("settings.conf", QSettings::IniFormat);
    settings.clear();
    return true;
}




