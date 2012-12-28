#ifndef SOURCE_H
#define SOURCE_H

#include <QMultiMap>

#include "row.h"
#include "metamodel/event.h"

class Source : public Row
{

private:
    QMultiMap<unsigned long long int, LogEvent *> events;
    LogEvent * findEvent(int x);
    LogEvent * findEvent(unsigned long long int ts);
    QString name;

protected:
    virtual QWidget * getSideWidgetBase();
    virtual void mousePressed(int x, int y);
    virtual void paint(QRect rect);

public:
    explicit Source(QWidget *parent = 0);
    void addLogEvent(LogEvent * logEvent);

    void setName(QString name);
    QString * getName();

signals:
    
public slots:
    
};

#endif // SOURCE_H
