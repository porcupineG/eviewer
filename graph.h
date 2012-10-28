#ifndef GRAPH_H
#define GRAPH_H

#include <QGraphicsItem>

class Graph :
        public QObject,
        public QGraphicsItem
{
    Q_OBJECT

private:
    QGraphicsPolygonItem graph;
    QColor color;
    QRectF bounding;

protected:
    void mousePressEvent(QGraphicsSceneHoverEvent * event);
    void mouseReleaseEvent(QGraphicsSceneHoverEvent * event);

public:
    explicit Graph(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

signals:
    
public slots:
    void setData(QVector<QPointF> data);
};

#endif // GRAPH_H
