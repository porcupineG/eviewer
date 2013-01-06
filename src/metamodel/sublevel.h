#ifndef SUBLEVEL_H
#define SUBLEVEL_H

#include "logtype.h"

#include <QString>
#include <QMap>

class SubLevel
{
private:
    QString name;
    unsigned int ordinal;
    QMap<unsigned int, LogType *> logTypes;

public:
    SubLevel(QString name, unsigned int ordinal);
    void insert(LogType * logType);

    QMap<unsigned int, LogType *> * getLogTypes();
    QString * getName();
    unsigned int getOrdinal();

};

#endif // SUBLEVEL_H
