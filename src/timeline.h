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

class Timeline : public QTableWidget
{
    Q_OBJECT

private:
    QList<SourceRow *> sourceRowList;
    unsigned long long int startTime;
    unsigned long long int stopTime;

    QList<unsigned long long int> timestamps;
    double millisecPerPixel;

    QList<Source *> sources;
    QList<Graph *> graphs;

    bool eventFilter(QObject * object, QEvent * event);

    TimelineBar * timelineBar;

public:
    Timeline(QWidget * parent = 0);

    void addSource(Source * source);
    void addGraph(Graph * graph);
    void update();


signals:
    void timeRangeChanged(unsigned long long int startTime, unsigned long long int stopTime);
    void viewInfoWidget(QWidget * widget);

public slots:
    void zoomIn();
    void zoomOut();

    void setInfoWidget(QWidget * widget);

};

#endif // GRAPHICSVIEW_H
