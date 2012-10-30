#include "timeline.h"

#include <QDebug>
#include <qmath.h>

Timeline::Timeline(QWidget * parent) :
    QScrollBar(parent)
{
}

void Timeline::setTimeRange(qreal start, qreal stop)
{
    this->start = start;
    this->stop = stop;
}


void Timeline::paintEvent(QPaintEvent * paintEvent)
{
    QPainter painter(this);
    QPen pen(Qt::black);
    QBrush brush(Qt::green);
    painter.setPen(pen);
    painter.setBrush(brush);

    brush.setColor(Qt::red);
    painter.drawRect(paintEvent->rect());

    qreal secPerPixel = (stop - start) / (qreal) (maximum() - minimum() + pageStep());

    qreal startSec = sliderPosition() * secPerPixel;
    qreal stopSec = (sliderPosition() + pageStep()) * secPerPixel;
    qreal lengthSec = stopSec - startSec;
    qreal bigStep = qPow(10, qFloor(qLn(lengthSec) / qLn(10)));
    qreal smallStep = bigStep / 10;

    qDebug() << "---";
    qDebug() << startSec;
    qDebug() << stopSec;
    qDebug() << lengthSec;
    qDebug() << "";

    qreal small = qCeil(startSec / smallStep) * smallStep;
    while (small < stopSec) {
        if ((small / bigStep) != qRound(small / bigStep)) {
            qreal x = (small / secPerPixel) -  sliderPosition();
            painter.drawLine(QPointF(x, height() / 2), QPointF(x, height()));
        }
        small += smallStep;
    }

    qreal big = qCeil(startSec / bigStep) * bigStep;
    while (big < stopSec) {
        qreal x = (big / secPerPixel) -  sliderPosition();
        QRectF rect(x - bigStep / secPerPixel, 0, 2 * bigStep / secPerPixel, height());
        painter.drawText(rect, Qt::AlignHCenter | Qt::AlignTop, QString::number(big) + " s");
        pen.setWidth(2);
        painter.drawLine(QPointF(x, height() / 2), QPointF(x, height()));
        big += bigStep;
    }


}

QSize Timeline::sizeHint() const
{
    return QSize(0, 30);
}
