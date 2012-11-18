#include "timelinebar.h"
#include "timeline.h"

#include <QDebug>

TimelineBar::TimelineBar(QWidget *parent) :
    QCustomPlot(parent)
{
    addGraph();
    xAxis->setVisible(true);
    xAxis->setTickLabels(true);
    yAxis->setVisible(false);
    yAxis->setTickLabels(false);
    xAxis2->setVisible(false);
    xAxis2->setTickLabels(false);
    yAxis2->setVisible(false);
    yAxis2->setTickLabels(false);
    yAxis->setPadding(0);
    xAxis->setLabelPadding(0);
    xAxis->setAutoTickStep(true);
    xAxis->setAutoTicks(true);
    xAxis->setAutoTickCount(10);

    yAxis->setRange(0, 10);
    graph(0)->rescaleAxes(true);
    graph(0)->setLineStyle(QCPGraph::lsImpulse);
    graph(0)->setPen(QPen(QBrush(Qt::red), 3));
    //graph(0)->setScatterStyle(QCP::ssCircle);
    setAutoMargin(false);
    setMargin(0, 0, 20, 20);

}

void TimelineBar::setTimeRange(unsigned long long int startTime, unsigned long long int stopTime)
{
    xAxis->setRange(startTime, stopTime);
}

void TimelineBar::setMarker(unsigned long long marker)
{
    QVector<double> x;
    x.append(marker);
    QVector<double> y;
    y.append(10);
    graph(0)->setData(x, y);
    replot();
}

