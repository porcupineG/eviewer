#ifndef TYPEVALUE_H
#define TYPEVALUE_H

#include "idvalue.h"
#include "idname.h"
#include "levelname.h"
#include "typename.h"
#include "typevalue.h"
#include "../metamodel/event.h"

#include <QMultiMap>
#include <QTreeWidgetItem>

class LogEvent;
class TypeName;

class TypeValue
{
private:
    TypeName * parent;
    QMultiMap<unsigned long long int, LogEvent *> childs;
    unsigned long long int value;
    QTreeWidgetItem * treeWidgetItem;


public:
    TypeValue(unsigned long long int value);
    QMultiMap<unsigned long long int, LogEvent *> * getChilds();
    void insertChild(LogEvent * value);
    unsigned long long int getValue();
    TypeName * getParent();
    void setParent(TypeName * parent);
    QTreeWidgetItem * getTreeWidgetItem();

};

#endif // TYPEVALUE_H
