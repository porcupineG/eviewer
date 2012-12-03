#include "timelinebar.h"
#include "graph.h"
#include "timeline.h"

#include <QScrollBar>
#include <QDebug>
#include <QLabel>
#include <QHeaderView>
#include <QWheelEvent>
#include "qcustomplot.h"

Timeline::Timeline(QWidget * parent) :
    QTableWidget(parent),
    millisecPerPixel(1.0)
{

    horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    horizontalHeader()->hide();

    viewport()->setMouseTracking(true);
    viewport()->installEventFilter(this);
    installEventFilter(this);

    overlay = new Overlay(viewport());

    horizontalScrollBar()->setTracking(true);
    connect(horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(sliderMoved(int)));
}

void Timeline::addSource(Source * source)
{
    sources.append(source);


    foreach (unsigned long long int ts, source->geTimestamps()) {
        if (timestamps.contains(ts) == false) {
            timestamps.append(ts);
        }
    }

    qSort(timestamps);
}

void Timeline::addGraph(Graph * graph)
{
    graphs.append(graph);
}

void Timeline::zoomIn()
{
    double frac = millisecPerPixel / 10.0;

    if (millisecPerPixel > (2 * frac)) {
        millisecPerPixel -= frac;
        update();
        overlay->raise();
    }

}

void Timeline::zoomOut()
{
    double frac = millisecPerPixel / 10.0;
    millisecPerPixel += frac;
    update();
    overlay->raise();
}

void Timeline::setInfoWidget(QWidget * widget)
{
    emit viewInfoWidget(widget);
}

void Timeline::sliderMoved(int value)
{
    qDebug() << value;
}

void Timeline::update()
{

    // Clear all table
    clear();
    clearContents();

    // Set row and column count to fit sources and graphs
    setRowCount(graphs.count() + sources.count() + 1);
    setColumnCount(timestamps.count());

    // Set Timeline
    setSpan(0, 0, 1, columnCount());
    timelineBar = new TimelineBar();
    setCellWidget(0, 0, timelineBar);
    setVerticalHeaderItem(0, timelineBar->getSideWidget(0));
    verticalHeader()->setResizeMode(0, QHeaderView::Fixed);
    connect(verticalHeader(), SIGNAL(sectionClicked(int)), timelineBar, SLOT(rowClicked(int)));
    connect(timelineBar, SIGNAL(setInfoWidget(QWidget *)), this, SLOT(setInfoWidget(QWidget *)));

    // Find start and stop for timerange
    totalStartTime = timestamps.first();
    totalStopTime = timestamps.last() + 100;
    timelineBar->setTimeRange(totalStartTime, totalStopTime);


    int rows = 1;

    for (int i = 0; i < graphs.count(); i++) {
        setVerticalHeaderItem(rows, graphs[i]->getSideWidget(rows));
        setSpan(rows, 0, 1, columnCount());
        setCellWidget(rows, 0, graphs[i]->getWidget());
        graphs[i]->setTimeRange(totalStartTime, totalStopTime);
        rows++;
    }

    for (int i = 0; i < sources.count(); i++) {
        setVerticalHeaderItem(rows, sources[i]->getSideWidget());
        for (int j = 0; j < (sources[i]->geTimestamps().count() - 1); j++) {
            int start = timestamps.indexOf(sources[i]->geTimestamps()[j]);
            int stop = timestamps.indexOf(sources[i]->geTimestamps()[j + 1]);

            if ((stop - start) > 1) {
                setSpan(rows, start, 1, stop - start);
            }

            setItem(rows, start, sources[i]->getEventWidget());
            item(rows, start)->setBackgroundColor(Qt::red);
        }

        int start = timestamps.indexOf(sources[i]->geTimestamps().last());
        int stop = timestamps.count();

        if ((stop - start) > 1) {
            setSpan(rows, start, 1, stop - start);
        }
        setItem(rows, start, sources[i]->getEventWidget());
        item(rows, start)->setBackgroundColor(Qt::green);

        rows++;
    }

    for (int i = 1; i < (timestamps.count()); i++) {
        setColumnWidth(i - 1, qRound(((double) timestamps.at(i) - (double) timestamps.at(i - 1)) / millisecPerPixel));
    }
    resize(size());
}

bool Timeline::eventFilter(QObject * object, QEvent * event)
{

    if (object == this && event->type() == QEvent::Resize) {
        QResizeEvent * resizeEvent = static_cast<QResizeEvent *>(event);
        overlay->resize(resizeEvent->size());
        overlay->raise();

        qDebug() << "viewport w" << viewport()->size().width();
        qDebug() << "viewport h" << viewport()->size().height();
        qDebug() << "this w" << verticalScrollBar()->pos().x();
        qDebug() << "this h" << contentsRect().height();
    }

    if (object == viewport() && event->type() == QEvent::Wheel) {
        QWheelEvent * wheelEvent = static_cast<QWheelEvent *>(event);
        if (wheelEvent->delta() > 0) {
            zoomIn();
        } else {
            zoomOut();
        }
    }

    if (object == viewport() && event->type() == QEvent::MouseMove) {
        QMouseEvent * mouseEvent = static_cast<QMouseEvent *>(event);

        overlay->setMainMarkerPosition(mouseEvent->x());
        overlay->repaint();
        overlay->raise();
    }

    return false;
}
