#ifndef LOGTYPE_H
#define LOGTYPE_H

#include "logcode.h"

#include <QMap>

class LogType
{
private:
    QMap<unsigned int, LogCode> logCodes;
    unsigned int value;
    QString name;
    bool indicator;
    unsigned int priority;
    unsigned int logStruct;

public:
    LogType();
    LogType(unsigned int value, QString name, bool indicator, unsigned int priority, unsigned int logStruct);
    void insert(LogCode logCode);

    QMap<unsigned int, LogCode> getLogCodes();
    unsigned int getValue();
    QString getName();
    bool getIndicator();
    unsigned int getPriority();
    unsigned int getLogStruct();

};

#endif // LOGTYPE_H
