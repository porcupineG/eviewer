#ifndef TIMELINE_H
#define TIMELINE_H

#include <QTableWidgetItem>

#include "infowidget.h"
#include "qcustomplot.h"

class TimelineBar : public QCustomPlot
{
    Q_OBJECT

private:
    InfoWidget * infoWidget;
    QTableWidgetItem * sideWidget;
    int row;
    unsigned long long int startTime;
    unsigned long long int stopTime;

protected:
    void mousePressEvent(QMouseEvent *event);

public:
    explicit TimelineBar(QWidget * parent = 0);
    QTableWidgetItem * getSideWidget(int row);

signals:
    void setInfoWidget(QWidget * widget);
    
public slots:
    void setTimeRange(unsigned long long int start, unsigned long long int stop);
    void rowClicked(int row);

};

#endif // TIMELINE_H
