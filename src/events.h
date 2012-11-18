#ifndef EVENT_H
#define EVENT_H

#include "sourcerow.h"

class Events :
    public SourceRow
{
    Q_OBJECT

private:
    QColor color;

public:
    explicit Events(QWidget * parent = 0);

public slots:
    void viewInfo(QWidget & widget);

};


#endif // EVENT_H
