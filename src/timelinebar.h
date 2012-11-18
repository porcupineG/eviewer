#ifndef TIMELINE_H
#define TIMELINE_H

#include "qcustomplot/qcustomplot.h"

class TimelineBar : public QCustomPlot
{
    Q_OBJECT

public:
    explicit TimelineBar(QWidget * parent = 0);
    
signals:
    
public slots:
    void setTimeRange(unsigned long long int start, unsigned long long int stop);
    void setMarker(unsigned long long int marker);

};

#endif // TIMELINE_H
