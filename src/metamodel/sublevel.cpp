#include "sublevel.h"

SubLevel::SubLevel(QString name, unsigned int ordinal)
{
    this->name = name;
    this->ordinal = ordinal;
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

unsigned int SubLevel::getOrdinal()
{
    return ordinal;
}
