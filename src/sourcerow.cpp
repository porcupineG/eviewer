#include "sourcerow.h"

#include <QDebug>

SourceRow::SourceRow(QWidget * parent) :
    QWidget(parent),
    sideWidget(),
    selected(true)
{

}

unsigned long long SourceRow::getStartTime()
{
    return startTime;
}

unsigned long long SourceRow::getStopTime()
{
    return stopTime;
}

QWidget * SourceRow::getSideWidget()
{
    return &sideWidget;
}


void SourceRow::mousePressEvent(QMouseEvent * event)
{
//    selected = true;
//    qDebug() << event->x();
}
