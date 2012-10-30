#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
private:
    QGraphicsScene mainScene;

protected:
    QPointF CurrentCenterPoint;
    QPoint LastPanPoint;
    void SetCenter(const QPointF& centerPoint);
    QPointF GetCenter() { return CurrentCenterPoint; }
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);
    void resizeEvent(QResizeEvent* event);

public:
    GraphicsView();

};

#endif // GRAPHICSVIEW_H
