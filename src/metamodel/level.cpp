#include "level.h"

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
    ids.insert(0, id);
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

LogType * Level::getLogType(unsigned long long type)
{
    for (int i = 0; i < subLevels.count(); i++) {

        if (*(subLevels[i].getLogTypes().find(type)) == NULL) {
            qDebug() << "chuj";
        }
    }

    return 0;
}
