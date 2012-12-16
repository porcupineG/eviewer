#ifndef ROW_H
#define ROW_H

#include <QWidget>
#include <QEvent>
#include <QObject>

#include "infowidget.h"

class Row : public QWidget
{
    Q_OBJECT

private:
    QWidget * sideWidget;

    bool eventFilter(QObject * obj, QEvent * ev);

protected:
    virtual QWidget * getSideWidgetBase() = 0;
    virtual void mousePressed(int x, int y) = 0;
    virtual void paint(QRect rect) = 0;

    double pixPerMs;

    unsigned long long int globalStartTime;
    unsigned long long int globalStopTime;

    unsigned long long int startTime;
    unsigned long long int stopTime;

public:
    explicit Row(QWidget * parent = 0);
    QWidget * getSideWidget();

    unsigned long long int getStartTime();
    unsigned long long int getStopTime();

signals:
    void setInfoWidget(QWidget * widget);

public slots:
    void setTimeRange(unsigned long long globalStartTime, unsigned long long globalStopTime);

};

#endif // ROW_H
