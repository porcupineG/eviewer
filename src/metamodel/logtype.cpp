#include "logtype.h"

#include <QDebug>

LogType::LogType()
{
}

LogType::LogType(unsigned int value, QString name)
{
    this->value = value;
    this->name = QString(name);

    this->logStruct = (value & 0xf000) >> 12;
    this->indicator = ((value & 0x800) != 0);
    this->priority =  (value & 0x600) >> 9;
    this->logLevel =  (value & 0x1c0) >> 6;
    this->logType =  (value & 0x3f);
}

LogType::LogType(unsigned int logStruct, bool indicator, unsigned int priority, unsigned int logLevel, unsigned int logType, QString name)
{
    this->logStruct = (logStruct & 0xf);
    this->indicator = indicator;
    this->priority = (priority & 0x03);
    this->logLevel = (logLevel & 0x07);
    this->logType = (logType & 0x3f);

    value = 0;
    value += (unsigned int) (this->logStruct << 12);

    if (this->indicator == true) {
        value += (0x1 << 10);
    }

    value += (unsigned int) (this->priority << 9);
    value += (unsigned int) (this->logLevel << 6);
    value += (unsigned int) (this->logType);

    this->name = QString(name);

}

QMap<unsigned int, LogCode> * LogType::getLogCodes()
{
    return &logCodes;
}

unsigned int LogType::getValue()
{
    return value;
}

QString * LogType::getName()
{

    return &name;
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

unsigned int LogType::getLogLevel()
{
    return logLevel;
}

unsigned int LogType::getLogType()
{
    return logType;
}

void LogType::print()
{
    qDebug() << "value" << value;
    qDebug() << "indicator" << indicator;
    qDebug() << "priority" << priority;
    qDebug() << "logStruct" << logStruct;
    qDebug() << "logLevel" << logLevel;
    qDebug() << "logType" << logType;
    qDebug() << "name" << name;
}

void LogType::insert(LogCode logCode)
{
    logCodes.insert(logCode.getValue(),  logCode);
}
