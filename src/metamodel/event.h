#ifndef EVENT_H
#define EVENT_H

#include <QList>

#include "id.h"
#include "logtype.h"

class LogEvent
{
private:
    LogType type;
    unsigned int length;
    unsigned long long int timestamp;
    unsigned int code;
    QList<Id> ids;
    float indicator;

public:
    LogEvent(LogType type, unsigned int length, unsigned int timestamp, unsigned int code, float indicator);

    LogType getType();
    unsigned int getLength();
    unsigned long long int getTimestamp();
    unsigned int getCode();
    QList<Id> getIds();
    float getIndicator();

    void insertId(Id);

};

#endif // EVENT_H
