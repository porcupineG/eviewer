#include "eventscollector.h"

EventsCollector::EventsCollector(QObject *parent) :
    QObject(parent)
{

}


std::istream & operator >> (std::istream & in, EventsCollector & eventsCollector) {
    return in;
}
