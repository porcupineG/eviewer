#ifndef LEVEL_H
#define LEVEL_H

#include "sublevel.h"
#include "id.h"

#include <QList>

class Level
{
private:
    QList<SubLevel> subLevels;
    QList<Id> ids;
    QString name;

public:
    Level(QString name);
    void insert(SubLevel subLevel);
    void insert(Id id);

    QList<SubLevel> getSubLevels();
    QList<Id> getIds();
    QString getName();

    LogType * getLogType(unsigned long long int type);
};

#endif // LEVEL_H
