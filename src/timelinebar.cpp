#include "timelinebar.h"
#include "timeline.h"

#include <QDebug>

TimelineBar::TimelineBar(QWidget * parent) :
    Row(parent),
    plot(parent)
{
    plot.addGraph();
    plot.xAxis->setVisible(true);
    plot.xAxis->setTickLabels(true);
    plot.yAxis->setVisible(false);
    plot.yAxis->setTickLabels(false);
    plot.xAxis2->setVisible(false);
    plot.xAxis2->setTickLabels(false);
    plot.yAxis2->setVisible(false);
    plot.yAxis2->setTickLabels(false);
    plot.yAxis->setPadding(0);
    plot.xAxis->setLabelPadding(0);
    plot.xAxis->setAutoTickStep(true);
    plot.xAxis->setAutoTicks(true);
    plot.xAxis->setAutoTickCount(10);

    plot.yAxis->setRange(0, 10);
    plot.graph(0)->rescaleAxes(true);
    plot.graph(0)->setLineStyle(QCPGraph::lsImpulse);
    plot.graph(0)->setPen(QPen(QBrush(Qt::red), 3));
    plot.setAutoMargin(false);
    plot.setMargin(0, 0, 20, 20);
}

void TimelineBar::paint(QRect rect)
{

}


void TimelineBar::mousePressed(int x, int y)
{
    InfoWidget * infoWidget = new InfoWidget();
    infoWidget->setTopLevelName("Timeline");
    infoWidget->addLevel("Total range");
    infoWidget->addSublevel("Total range", "start", QVariant(startTime), "ms");
    infoWidget->addSublevel("Total range", "stop", QVariant(globalStopTime), "ms");

    emit setInfoWidget(infoWidget);
}


QWidget * TimelineBar::getSideWidgetBase()
{
    return 0;
}
