#include "timelinebar.h"
#include "graph.h"
#include "timeline.h"

#include <QScrollBar>
#include <QDebug>
#include <QLabel>
#include <QHeaderView>
#include "qcustomplot/qcustomplot.h"

Timeline::Timeline(QWidget * parent) :
    QTableWidget(parent),
    millisecPerPixel(1.0)
{

    horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    horizontalHeader()->hide();

    viewport()->setMouseTracking(true);
    viewport()->installEventFilter(this);
    installEventFilter(this);

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

}

void Timeline::zoomIn()
{
    double frac = millisecPerPixel / 10.0;

    if (millisecPerPixel > (2 * frac)) {
        millisecPerPixel -= frac;
        update();
    }

}

void Timeline::zoomOut()
{
    double frac = millisecPerPixel / 10.0;
    millisecPerPixel += frac;
    update();
}


void Timeline::update()
{

    clear();
    clearContents();

    setRowCount(graphs.count() + sources.count() + 1);
    setColumnCount(timestamps.count());

    setSpan(0, 0, 1, timestamps.count());
    timelineBar = new TimelineBar();
    setCellWidget(0, 0, timelineBar);
//    takeVerticalHeaderItem(0)->setText("Timeline");

    startTime = timestamps.first();
    stopTime = timestamps.last() + 100;
    timelineBar->setTimeRange(startTime, stopTime);

    int rows = 1;

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
        qDebug() << resizeEvent->size().width();

    }

    if (object == viewport() && event->type() == QEvent::MouseMove) {
        QMouseEvent * mouseEvent = static_cast<QMouseEvent *>(event);
        timelineBar->setMarker(mouseEvent->x());
    }


    return false;
}
