#ifndef TIMELINE_H
#define TIMELINE_H

#include <QTableWidgetItem>

#include "qcustomplot.h"
#include "row.h"

class TimelineBar : public Row, public QCustomPlot
{
    Q_OBJECT

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
