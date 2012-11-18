#ifndef SOURCEROW_H
#define SOURCEROW_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class SourceRow :
        public QWidget
{
    Q_OBJECT

private:
    bool visible;
    unsigned long long int startTime;
    unsigned long long int stopTime;

protected:
    QWidget sideWidget;
    bool selected;
    void mousePressEvent(QMouseEvent * event);

public:
    explicit SourceRow(QWidget * parent = 0);

    unsigned long long int getStartTime();
    unsigned long long int getStopTime();
    QWidget * getSideWidget();

signals:
    
public slots:
    virtual void viewInfo(QWidget & widget) = 0;

};

#endif // SOURCEROW_H
