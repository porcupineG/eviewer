#include "graph.h"
#include "float.h"

#include <QPainter>
#include <QDebug>

Graph::Graph(QObject * parent) :
    QObject(parent),
    QGraphicsItem()
{
    graph.setBrush(QBrush(Qt::blue));
    QPen pen;
    //pen.setWidth(1);
    graph.setPen(pen);
    setAcceptHoverEvents(true);

}

void Graph::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    painter->drawRect(bounding);

    graph.paint(painter, option, widget);
}

QRectF Graph::boundingRect() const
{
    return bounding;
}

void Graph::setData(QVector<QPointF> data)
{
    data.push_front(QPointF(data.front().x(), 0));
    data.push_back(QPointF(data.back().x(), 0));

    QPolygonF polygon(data);
    bounding = polygon.boundingRect();
    graph.setPolygon(QPolygonF(data));

}


void Graph::mousePressEvent(QGraphicsSceneHoverEvent *event)
{
    graph.setBrush(QBrush(Qt::red));
    update();
    qDebug() << "asd";
}

void Graph::mouseReleaseEvent(QGraphicsSceneHoverEvent *event)
{
    graph.setBrush(QBrush(Qt::blue));
    update();
    qDebug() << "23";
}
