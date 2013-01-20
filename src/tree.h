#ifndef TREE_H
#define TREE_H

#include "tree/idvalue.h"
#include "tree/idname.h"
#include "tree/levelname.h"
#include "tree/typename.h"
#include "tree/typevalue.h"
#include "metamodel/event.h"

class Tree
{
    IdValue * root;

public:
    Tree();
    IdName * getRoot();
    void insert(LogEvent * event);

};

#endif // TREE_H
