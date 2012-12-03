#include "event.h"

Event::Event()
{
}

unsigned int Event::getType()
{
    return type;
}

unsigned int Event::getLength()
{
    return length;
}

unsigned long long Event::getTimestamp()
{
    return timestamp;
}

unsigned int Event::getCode()
{
    return code;
}

QList<unsigned int> Event::getIds()
{
    return ids;
}

float Event::getIndicator()
{
    return indicator;
}
