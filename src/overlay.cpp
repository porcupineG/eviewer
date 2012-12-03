#include "overlay.h"



Overlay::Overlay(QWidget *parent) :
    QWidget(parent)
{
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setPalette(Qt::transparent);
    setAutoFillBackground(false);
    raise();
}

void Overlay::setMainMarkerPosition(int position)
{
    mutex.lock();
    mainMarkerPosition = position;
    mutex.unlock();
}


void Overlay::paintEvent(QPaintEvent * paintEvent)
{
    QPainter painter(this);
    drawMainMarker(&painter);

    paintEvent->accept();
}


void Overlay::drawMainMarker(QPainter * painter)
{
    mutex.lock();
    painter->fillRect(mainMarkerPosition - 1, 0, 2, size().height(), QColor::fromRgba(qRgba(50, 50, 50, 200)));
    mutex.unlock();
}
