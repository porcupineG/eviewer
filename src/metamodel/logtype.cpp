#include "logtype.h"

LogType::LogType()
{
}

LogType::LogType(unsigned int value, QString name, bool indicator, unsigned int priority, unsigned int logStruct)
{
    this->value = value;
    this->name = name;
    this->indicator = indicator;
    this->priority = priority;
    this->logStruct = logStruct;
}

QMap<unsigned int, LogCode> LogType::getLogCodes()
{
    return logCodes;
}

unsigned int LogType::getValue()
{
    return value;
}

QString LogType::getName()
{
    return name;
}

bool LogType::getIndicator()
{
    return indicator;
}

unsigned int LogType::getPriority()
{
    return priority;
}

unsigned int LogType::getLogStruct()
{
    return logStruct;
}

void LogType::insert(LogCode logCode)
{
    logCodes.insert(logCode.getValue(),  logCode);
}
