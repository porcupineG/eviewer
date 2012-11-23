#include "source.h"

Source::Source(QObject * parent) :
    QObject(parent)
{
}

void Source::addTimestamp(unsigned long long int timestamp)
{
    timestamps.append(timestamp);
}

QList<unsigned long long int> Source::geTimestamps()
{
    return timestamps;
}

QTableWidgetItem * Source::getSideWidget()
{
    return new QTableWidgetItem();
}

QTableWidgetItem * Source::getEventWidget()
{
    return new QTableWidgetItem();
}