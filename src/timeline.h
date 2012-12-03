#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QTableWidget>
#include <QGridLayout>
#include <QList>
#include <QSet>
#include <QResizeEvent>

#include "source.h"
#include "graph.h"

#include "timelinebar.h"
#include "overlay.h"

class Timeline : public QTableWidget
{
    Q_OBJECT

private:

    QList<unsigned long long int> timestamps;
    double millisecPerPixel;
    unsigned long long int totalStartTime;
    unsigned long long int totalStopTime;
    unsigned long long int visibleStartTime;
    unsigned long long int visibleStopTime;

    QList<Source *> sources;
    QList<Graph *> graphs;

    bool eventFilter(QObject * object, QEvent * event);

    TimelineBar * timelineBar;
    Overlay * overlay;

public:
    Timeline(QWidget * parent = 0);

    void addSource(Source * source);
    void addGraph(Graph * graph);
    void update();


signals:
    void totalTimeRangeChanged(unsigned long long int totalStartTime, unsigned long long int stopTime);
    void visibleTimeRangeChanged(unsigned long long int totalStartTime, unsigned long long int stopTime);
    void mainMarkerPositionChanged(unsigned long long int time);
    void viewInfoWidget(QWidget * widget);

public slots:
    void zoomIn();
    void zoomOut();

    void setInfoWidget(QWidget * widget);
    void sliderMoved(int value);
};

#endif // GRAPHICSVIEW_H
