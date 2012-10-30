#include "graphicsview.h"
#include "graph.h"
#include "timeline.h"

#include <qmath.h>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTextStream>
#include <QScrollBar>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QDebug>

GraphicsView::GraphicsView()
{
    setScene(&mainScene);

    Graph * graph = new Graph();
    mainScene.addItem(graph);

    QVector<QPointF> data;
    for (int i = 0; i < 10000; i++) {
        data.append(QPointF(i, 1 * qSin(i * 0.01)));
    }


    graph->setData(data);

    fitInView(graph);
    setDragMode(RubberBandDrag);

    SetCenter(QPointF(500.0, 500.0)); //A modified version of centerOn(), handles special cases
    setCursor(Qt::OpenHandCursor);

    Timeline * timeline = new Timeline(this);
    setHorizontalScrollBar(timeline);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    timeline->setTimeRange(0, 1000);

    setLayoutDirection(Qt::RightToLeft);
}

void GraphicsView::SetCenter(const QPointF& centerPoint) {
    QRectF visibleArea = mapToScene(rect()).boundingRect();

    QRectF sceneBounds = sceneRect();

    double boundX = visibleArea.width() / 2.0;
    double boundY = visibleArea.height() / 2.0;
    double boundWidth = sceneBounds.width() - 2.0 * boundX;
    double boundHeight = sceneBounds.height() - 2.0 * boundY;

    QRectF bounds(boundX, boundY, boundWidth, boundHeight);

    if(bounds.contains(centerPoint)) {
        CurrentCenterPoint = centerPoint;
    } else {
        if(visibleArea.contains(sceneBounds)) {
            CurrentCenterPoint = sceneBounds.center();
        } else {

            CurrentCenterPoint = centerPoint;

            if(centerPoint.x() > bounds.x() + bounds.width()) {
                CurrentCenterPoint.setX(bounds.x() + bounds.width());
            } else if(centerPoint.x() < bounds.x()) {
                CurrentCenterPoint.setX(bounds.x());
            }

            if(centerPoint.y() > bounds.y() + bounds.height()) {
                CurrentCenterPoint.setY(bounds.y() + bounds.height());
            } else if(centerPoint.y() < bounds.y()) {
                CurrentCenterPoint.setY(bounds.y());
            }

        }
    }

    centerOn(CurrentCenterPoint);
}

void GraphicsView::mousePressEvent(QMouseEvent* event) {
    LastPanPoint = event->pos();
    setCursor(Qt::ClosedHandCursor);
}

void GraphicsView::mouseReleaseEvent(QMouseEvent* event) {
    setCursor(Qt::OpenHandCursor);
    LastPanPoint = QPoint();
}

void GraphicsView::mouseMoveEvent(QMouseEvent* event) {
    if(!LastPanPoint.isNull()) {
        QPointF delta = mapToScene(LastPanPoint) - mapToScene(event->pos());
        LastPanPoint = event->pos();
        SetCenter(GetCenter() + delta);
    }
}

void GraphicsView::wheelEvent(QWheelEvent* event) {

    QPointF pointBeforeScale(mapToScene(event->pos()));

    QPointF screenCenter = GetCenter(); //CurrentCenterPoint; //(visRect.center());

    double scaleFactor = 1.15; //How fast we zoom
    if(event->delta() > 0) {
        scale(scaleFactor, scaleFactor);
    } else {
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }

    QPointF pointAfterScale(mapToScene(event->pos()));

    QPointF offset = pointBeforeScale - pointAfterScale;

    QPointF newCenter = screenCenter + offset;
    SetCenter(newCenter);
}

void GraphicsView::resizeEvent(QResizeEvent* event) {
    QRectF visibleArea = mapToScene(rect()).boundingRect();
    SetCenter(visibleArea.center());
    QGraphicsView::resizeEvent(event);
}
