#ifndef LOGTYPE_H
#define LOGTYPE_H

#include "logcode.h"

#include <QMap>

class LogType
{
private:
    unsigned int value;
    bool indicator;
    unsigned int priority;
    unsigned int logStruct;
    unsigned int logLevel;
    unsigned int logType;

    QMap<unsigned int, LogCode> logCodes;
    QString name;

public:
    LogType();
    LogType(unsigned int value, QString name);
    LogType(unsigned int logStruct, bool indicator, unsigned int priority, unsigned int logLevel, unsigned int logType, QString name);

    void insert(LogCode logCode);

    QMap<unsigned int, LogCode> * getLogCodes();
    unsigned int getValue();
    QString * getName();
    bool getIndicator();
    unsigned int getPriority();
    unsigned int getLogStruct();
    unsigned int getLogLevel();
    unsigned int getLogType();

    void print();
};

#endif // LOGTYPE_H
