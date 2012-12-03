#ifndef EVENT_H
#define EVENT_H

#include <QList>

class Event
{
private:
    unsigned int type;
    unsigned int length;
    unsigned long long int timestamp;
    unsigned int code;
    QList<unsigned int> ids;
    float indicator;

public:
    Event();

    unsigned int getType();
    unsigned int getLength();
    unsigned long long int getTimestamp();
    unsigned int getCode();
    QList<unsigned int> getIds();
    float getIndicator();

};

#endif // EVENT_H
