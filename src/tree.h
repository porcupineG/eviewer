#ifndef TREE_H
#define TREE_H

#include "tree/idvalue.h"
#include "tree/idname.h"
#include "tree/levelname.h"
#include "tree/typename.h"
#include "tree/typevalue.h"
#include "metamodel/event.h"

#include <QMap>

#include <QTreeWidget>

class Tree
{
    IdValue * root;
    QTreeWidget treeWidget;
    QMap<unsigned long long int, TypeValue *> typeValues;

    unsigned long long int globalStopTime;
    unsigned long long int globalStartTime;
    double millisecPerPixel;

public:
    Tree();
    IdName * getRoot();
    QTreeWidget * getTreeWidget();
    void insert(LogEvent * event);
    void zoomIn();
    void zoomOut();
    void updateWidgets();
    void sizeUpdate();
};

#endif // TREE_H
