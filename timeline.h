#ifndef TIMELINE_H
#define TIMELINE_H

#include <QScrollBar>
#include <QPainter>
#include <QPaintEvent>

class Timeline : public QScrollBar
{
    Q_OBJECT

private:
    qreal start;
    qreal stop;

protected:
    void paintEvent(QPaintEvent * paintEvent);
    QSize sizeHint() const;

public:
    explicit Timeline(QWidget * parent = 0);
    
signals:
    
public slots:
    void setTimeRange(qreal start, qreal stop);
    
};

#endif // TIMELINE_H
