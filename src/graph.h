#ifndef GRAPH_H
#define GRAPH_H

#include <QTableWidgetItem>

#include "infowidget.h"
#include "qcustomplot.h"

class Graph : public QObject
{
    Q_OBJECT

private:
    InfoWidget * infoWidget;
    QTableWidgetItem * sideWidget;
    QCustomPlot * widget;
    int row;
    unsigned long long int startTime;
    unsigned long long int stopTime;
    QVector<double> x;
    QVector<double> y;

public:
    explicit Graph(QWidget * parent = 0);
    QTableWidgetItem * getSideWidget(int row);
    QWidget * getWidget();

signals:
    void setInfoWidget(QWidget * widget);

public slots:
    void setTimeRange(unsigned long long int start, unsigned long long int stop);
    void rowClicked(int row);
    void addData(QVector<double> & x, QVector<double> & y);
    void appendData(double timestamp, double value);

};

#endif // GRAPH_H
