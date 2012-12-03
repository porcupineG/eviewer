#ifndef OVERLAY_H
#define OVERLAY_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QMutex>

class Overlay : public QWidget
{
    Q_OBJECT

private:
    QMutex mutex;
    int mainMarkerPosition;

    void drawMainMarker(QPainter * painter);

protected:
    void paintEvent(QPaintEvent * paintEvent);

public:
    explicit Overlay(QWidget *parent = 0);
    
signals:
    
public slots:
    void setMainMarkerPosition(int position);
    
};

#endif // OVERLAY_H
