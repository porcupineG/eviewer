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
    setAutoMargin(false);
    setMargin(0, 0, 20, 20);
}

void TimelineBar::setTimeRange(unsigned long long int startTime, unsigned long long int stopTime)
{
    this->startTime = startTime;
    this->stopTime = stopTime;
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

void TimelineBar::itemClicked(QTableWidgetItem * item)
{

}

void TimelineBar::rowClicked(int row)
{
    if (this->row == row) {
        infoWidget = new InfoWidget();
        infoWidget->setTopLevelName("Timeline");
        infoWidget->addLevel("Total range");
        infoWidget->addSublevel("Total range", "start", QVariant(startTime), "ms");
        infoWidget->addSublevel("Total range", "stop", QVariant(stopTime), "ms");

        emit setInfoWidget(infoWidget);
    }
}

QTableWidgetItem * TimelineBar::getSideWidget(int row)
{
    this->row = row;
    sideWidget = new QTableWidgetItem();
    sideWidget->setText("Timeline");
    sideWidget->setTextAlignment(Qt::AlignCenter);
    sideWidget->setFlags(Qt::NoItemFlags);
    sideWidget->setSizeHint(QSize(100, 30));
    return sideWidget;
}


