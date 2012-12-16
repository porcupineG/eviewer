#include "source.h"

#include <QLabel>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>

Source::Source(QWidget * parent) :
    Row(parent)
{
}

void Source::addLogEvent(LogEvent * logEvent)
{
    events.insert(logEvent->getTimestamp(), logEvent);

    if (logEvent->getTimestamp() > stopTime) {
        stopTime = logEvent->getTimestamp();
    }

    if (logEvent->getTimestamp() < startTime) {
        startTime = logEvent->getTimestamp();
    }

}

LogEvent * Source::findEvent(int x)
{
    unsigned long long int ts = globalStartTime + qRound64(x / pixPerMs);
    return findEvent(ts);
}

LogEvent * Source::findEvent(unsigned long long ts)
{
    QMultiMap<unsigned long long int, LogEvent *>::iterator it = events.lowerBound(ts);
    QMultiMap<unsigned long long int, LogEvent *>::iterator itNext = it;

    if (it != events.begin()) { it--; }
    if (it == events.end()) {
        return 0;
    }

    unsigned long long int tsFirst = it.key();

    QList<LogEvent *> list = events.values(tsFirst);
    int s = list.size();

    for (int i = 0; i < s; ++i) {
        itNext++;
    }

    unsigned long long int tsNext;
    if(itNext == events.end()) {
        tsNext = globalStopTime;
    } else {
        tsNext = itNext.key();
    }

    unsigned long long int tsDelta = tsNext - tsFirst;

    for (int i = 0; i < (ts / tsDelta); ++i) {
        it++;
    }

    return (*it);

}

QWidget * Source::getSideWidgetBase()
{
    QLabel * label = new QLabel("chuj");
}

void Source::mousePressed(int x, int y)
{

    LogEvent * event = findEvent(x);

    InfoWidget * infoWidget = new InfoWidget();
    infoWidget->setTopLevelName("Event");
    infoWidget->addLevel("LogType");
//    infoWidget->addSublevel("LogType", "Name", QVariant(*(*it)->getType()->getName()), "");
//    infoWidget->addSublevel("LogType", "Value", QVariant(QString::number(event->getType()->getValue(), 16)), "ms");
    infoWidget->addSublevel("LogType", "Timestamp", QVariant(event->getCode()), "ms");

    emit setInfoWidget(infoWidget);
}

void Source::paint(QRect rect)
{

    QPainter painter(this);

    int xR = rect.x();
    int yR = rect.y();
    int wR = rect.width();
    int hR = rect.height();

    int width = size().width();
    int height = size().height();

    unsigned long long tsBegin = globalStartTime + qRound64(xR / pixPerMs);
    unsigned long long tsEnd = tsBegin + + qRound64(wR / pixPerMs);

    QMultiMap<unsigned long long int, LogEvent *>::iterator it = events.lowerBound(tsBegin);
    if (it != events.begin()) { it--; }

    QMultiMap<unsigned long long int, LogEvent *>::iterator itNext = it;

    QMultiMap<unsigned long long int, LogEvent *>::iterator itEnd = events.upperBound(tsEnd);

    int color = 0;

    while((itNext != events.end()) && (it != events.end()) && (itNext != itEnd) && (it != itEnd)) {

        unsigned long long int ts = it.key();

        QList<LogEvent *> list = events.values(ts);
        int s = list.size();

        for (int i = 0; i < s; ++i) {
            itNext++;
        }

        unsigned long long int tsNext;
        if(itNext == events.end()) {
            tsNext = globalStopTime;
        } else {
            tsNext = itNext.key();
        }

        int w = qRound((((tsNext - ts) * pixPerMs) / s));
        int x = qRound((ts - globalStartTime) * pixPerMs);

        for (int i = 0; i < s; ++i) {

            if (color % 2) {
                painter.setBrush(QBrush(QColor::fromRgb(255, 0, 0)));
            } else {
                painter.setBrush(QBrush(QColor::fromRgb(0, 255, 0)));
            }

            painter.setPen(QPen(QBrush(QColor::fromRgb(0, 0, 0)), 2));

            int xx = x + i * w;

            if (s == 1) {
                painter.fillRect(xx, 0, w, height, Qt::SolidPattern);
            } else {
                painter.setBrush(QBrush(QColor::fromRgb(0, 0, 255)));
                painter.fillRect(xx, 0, w, height, Qt::CrossPattern);
            }
            painter.drawRect(xx, 0, w, height);

            it++;
            color++;
        }
    }

}
