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
    QTreeWidget(parent),
    millisecPerPixel(1.0)
{
    header()->hide();

    //horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    //horizontalHeader()->hide();

    viewport()->setMouseTracking(true);
    viewport()->installEventFilter(this);
    installEventFilter(this);

    overlay = new Overlay(this);

    horizontalScrollBar()->setTracking(true);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    connect(horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(sliderMoved(int)));

    globalStartTime = ULONG_LONG_MAX;
    globalStopTime = 0;

}

void Timeline::addSource(Source * source)
{
    int offset;

    if ((source->getStopTime() - offset)  > globalStopTime) {
        globalStopTime = source->getStopTime() + offset;
    }

    if (source->getStartTime() < globalStartTime) {
        globalStartTime = source->getStartTime();
    }

    source->setTimeRange(globalStartTime, globalStopTime);

    connect(source, SIGNAL(setInfoWidget(QWidget*)), this, SLOT(setInfoWidget(QWidget*)));
    sources.append(source);
}

void Timeline::addGraph(Graph * graph)
{
    //    graphs.append(graph);
}

void Timeline::setMetamodel(MetaModel *metamodel)
{
    this->metamodel = metamodel;

}

void Timeline::zoomIn()
{
    double frac = millisecPerPixel / 10.0;

    if (millisecPerPixel > (2 * frac)) {
        millisecPerPixel -= frac;
        this->sizeUpdate();
        overlay->raise();
    }

}

void Timeline::zoomOut()
{
    double frac = millisecPerPixel / 10.0;
    millisecPerPixel += frac;
    this->sizeUpdate();
    overlay->raise();
}

void Timeline::setInfoWidget(QWidget * widget)
{
    emit viewInfoWidget(widget);
}

void Timeline::sliderMoved(int value)
{
//    qDebug() << value;
}

void Timeline::sizeUpdate() {
    int w = qRound((globalStopTime - globalStartTime) / millisecPerPixel);
    setColumnWidth(1, w);
}

void Timeline::update()
{
    clear();
    //clearContents();

    //setRowCount(sources.count());

    setColumnCount(2);

    QTreeWidgetItem * topLevel = new QTreeWidgetItem();
    topLevel->setText(0, "Timeline");
    insertTopLevelItem(0, topLevel);
    setItemWidget(topLevel, 1, new TimelineBar());
    setItemExpanded(topLevel, true);

    int row = 0;
    foreach (Source * source, sources) {
        QTreeWidgetItem * child = new QTreeWidgetItem();
        child->setText(0, *source->getName());
        child->setSizeHint(1, QSize(100, 30));
        topLevel->addChild(child);
        setItemWidget(child, 1, source);
        setItemExpanded(child, true);
        row++;
    }

    resizeColumnToContents(0);

}

bool Timeline::eventFilter(QObject * object, QEvent * event)
{

    if (object == viewport() && event->type() == QEvent::Resize) {
        QResizeEvent * resizeEvent = static_cast<QResizeEvent *>(event);
        overlay->resize(resizeEvent->size());
        overlay->raise();
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
        qDebug() << "asdasd" << mouseEvent->x();
        overlay->setMainMarkerPosition(mouseEvent->x());
        overlay->repaint();
        overlay->raise();
    }

    return false;
}
