#ifndef ASEVENT_H
#define ASEVENT_H

#include <QList>

#include "id.h"
#include "logtype.h"
#include "sublevel.h"

class LogEvent
{
private:
    LogType * type;
    unsigned int length;
    unsigned long long int timestamp;
    unsigned int code;
    QList<Id *> ids;
    SubLevel * subLevel;

    float indicator;



public:
    LogEvent(LogType * type, unsigned int length, unsigned int timestamp, unsigned int code, float indicator, SubLevel * subLevel);

    LogType * getType();
    unsigned int getLength();
    unsigned long long int getTimestamp();
    unsigned int getCode();
    QList<Id *> * getIds();
    float getIndicator();
    SubLevel * getSubLevel();

    void insertId(Id *);

    void print();
};

#endif // ASEVENT_H
