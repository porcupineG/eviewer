#ifndef IDVALUE_H
#define IDVALUE_H

#include "idvalue.h"
#include "idname.h"
#include "levelname.h"
#include "typename.h"
#include "typevalue.h"
#include "../metamodel/event.h"

#include <QTreeWidgetItem>

class IdName;
class LevelName;

class IdValue
{

private:
    IdName * parent;
    IdName * child;
    QMap<QString, LevelName *> childs;
    unsigned long long int value;
    QTreeWidgetItem * treeWidgetItem;

public:
    IdValue(unsigned long long int value);

    void setParent(IdName * parent);
    IdName * getParent();
    void setChild(IdName * child);
    IdName * getChild();
    LevelName * insertChild(LevelName * child);
    QMap<QString, LevelName *> * getChilds();
    unsigned long long int getValue();
    QTreeWidgetItem * getTreeWidgetItem();


};

#endif // IDVALUE_H
