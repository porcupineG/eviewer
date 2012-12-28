#include "sublevel.h"

SubLevel::SubLevel(QString name)
{
    this->name = name;
}

void SubLevel::insert(LogType * logType)
{
    logTypes.insert(logType->getValue(), logType);
}

QMap<unsigned int, LogType *> * SubLevel::getLogTypes()
{
    return &logTypes;
}


QString * SubLevel::getName()
{
    return &name;
}
