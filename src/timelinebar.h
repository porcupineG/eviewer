#ifndef TIMELINE_H
#define TIMELINE_H

#include <QTableWidgetItem>

#include "qcustomplot.h"
#include "row.h"

class TimelineBar : public Row
{
    Q_OBJECT

private:
    QCustomPlot plot;

protected:
    virtual QWidget * getSideWidgetBase();
    virtual void mousePressed(int x, int y);
    virtual void paint(QRect rect);

public:
    explicit TimelineBar(QWidget * parent = 0);

};

#endif // TIMELINE_H
