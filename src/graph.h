#ifndef GRAPH_H
#define GRAPH_H

#include "sourcerow.h"

class Graph :
        public SourceRow
{

private:
    QColor color;

public:
    explicit Graph(QWidget * parent = 0);
    void paintEvent(QPaintEvent * event);

public slots:
    void viewInfo(QWidget & widget);

};

#endif // GRAPH_H
