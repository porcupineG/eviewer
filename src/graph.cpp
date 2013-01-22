#include "graph.h"

#include <QPainter>
#include <QDebug>

Graph::Graph(QWidget * parent) :
    QObject(parent)
{
}

QTableWidgetItem * Graph::getSideWidget(int row)
{
    this->row = row;
    sideWidget = new QTableWidgetItem();
    sideWidget->setText("Graph");
    sideWidget->setTextAlignment(Qt::AlignCenter);
    sideWidget->setFlags(Qt::NoItemFlags);
    sideWidget->setSizeHint(QSize(100, 30));
    return sideWidget;
}

QWidget * Graph::getWidget()
{
    widget = new QCustomPlot();
    widget->addGraph();
    widget->graph(0)->setData(x, y);
    widget->xAxis->setRange(startTime, stopTime);
    widget->yAxis->setRange(-1, 1);
    widget->setAutoMargin(false);
    widget->setMargin(0, 0, 20, 20);
    widget->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    widget->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    return widget;
}

void Graph::addData(QVector<double> & x, QVector<double> & y)
{
    this->x = x;
    this->y = y;
}

void Graph::appendData(double timestamp, double value)
{
    x.append(timestamp);
    y.append(value);
}


void Graph::rowClicked(int row)
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

void Graph::setTimeRange(unsigned long long start, unsigned long long stop)
{
    this->startTime = start;
    this->stopTime = stop;

    qDebug() << startTime;
}

