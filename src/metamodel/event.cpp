#include "event.h"

LogEvent::LogEvent(LogType type, unsigned int length, unsigned int timestamp, unsigned int code, float indicator)
{
    this->type = type;
    this->length = length;
    this->timestamp = timestamp;
    this->code = code;
    this->indicator = indicator;
}

LogType LogEvent::getType()
{
    return type;
}

unsigned int LogEvent::getLength()
{
    return length;
}

unsigned long long LogEvent::getTimestamp()
{
    return timestamp;
}

unsigned int LogEvent::getCode()
{
    return code;
}

QList<Id> LogEvent::getIds()
{
    return ids;
}

float LogEvent::getIndicator()
{
    return indicator;
}

void LogEvent::insertId(Id)
{
//    ids.insert(Id);
}
