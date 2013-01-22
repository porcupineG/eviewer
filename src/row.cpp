#include "row.h"

#include <QMouseEvent>
#include <QPaintEvent>
#include <QResizeEvent>

#include <QDebug>

Row::Row(QWidget * parent) :
    QWidget(parent)
{
    installEventFilter(this);

    startTime = ULONG_LONG_MAX;
    stopTime = 0;

    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
}

QWidget * Row::getSideWidget()
{
    sideWidget = getSideWidgetBase();
    sideWidget->installEventFilter(this);
    return sideWidget;
}

unsigned long long Row::getStartTime()
{
    return startTime;
}

unsigned long long Row::getStopTime()
{
    return stopTime;
}

void Row::setTimeRange(unsigned long long startTime, unsigned long long stopTime)
{
    this->globalStartTime = startTime;
    this->globalStopTime = stopTime;
}

bool Row::eventFilter(QObject * obj, QEvent * ev) {

    if (obj == sideWidget && ev->type() == QEvent::MouseButtonPress) {
        QMouseEvent * e = static_cast<QMouseEvent *>(ev);
        mousePressed(e->x(), e->y());
    }

    if (obj == this && ev->type() == QEvent::MouseButtonPress) {
        QMouseEvent * e = static_cast<QMouseEvent *>(ev);
        mousePressed(e->x(), e->y());
    }

    if ((obj == this) && (ev->type() == QEvent::Paint)) {
        QPaintEvent * e = static_cast<QPaintEvent *>(ev);
        paint(e->rect());
    }

    if ((obj == this) && (ev->type() == QEvent::Resize)) {
        QResizeEvent * e = static_cast<QResizeEvent *>(ev);
        this->pixPerMs = (double) e->size().width() / (double) (globalStopTime - globalStartTime);
        qDebug() << pixPerMs;
        repaint();
    }


    return true;
}
