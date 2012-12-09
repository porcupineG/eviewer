#ifndef SUBLEVEL_H
#define SUBLEVEL_H

#include "logtype.h"

#include <QString>
#include <QMap>

class SubLevel
{
private:
    QString name;
    QMap<unsigned int, LogType> logTypes;

public:
    SubLevel(QString name);
    void insert(LogType logType);

    QMap<unsigned int, LogType> * getLogTypes();
    QString * getName();

};

#endif // SUBLEVEL_H
