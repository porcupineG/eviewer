#ifndef TREE_H
#define TREE_H

#include "tree/idvalue.h"
#include "tree/idname.h"
#include "tree/levelname.h"
#include "tree/typename.h"
#include "tree/typevalue.h"
#include "metamodel/event.h"

#include <QTreeWidget>

class Tree
{
    IdValue * root;
    QTreeWidget treeWidget;

public:
    Tree();
    IdName * getRoot();
    QTreeWidget * getTreeWidget();
    void insert(LogEvent * event);

};

#endif // TREE_H
