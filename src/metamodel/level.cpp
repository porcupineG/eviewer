#include "level.h"
#include <iostream>
#include <QDebug>

Level::Level(QString name)
{
    this->name = name;
}

void Level::insert(SubLevel subLevel)
{
    subLevels.insert(0, subLevel);
}

void Level::insert(Id id)
{
    ids.insert(ids.end(), id);
}

QList<SubLevel> Level::getSubLevels()
{
    return subLevels;
}

QList<Id> Level::getIds()
{
    return ids;
}

QString Level::getName()
{
    return name;
}

LogType * Level::getLogType(unsigned int type)
{

    for (int i = 0; i < subLevels.count(); i++) {

        QMap<unsigned int, LogType> logTypes = subLevels[i].getLogTypes();
        QMap<unsigned int, LogType>::iterator it = logTypes.find(type);
        if (it != logTypes.end()) {
            return &(*it);
        }

    }

    return 0;
}
