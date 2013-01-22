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

#include "../source.h"
#include "../graph.h"

class LogEvent;
class TypeName;

class TypeValue
{
private:
    TypeName * parent;
    QMultiMap<unsigned long long int, LogEvent *> childs;
    Source * source;
    Graph * graph;
    unsigned long long int value;
    QTreeWidgetItem * treeWidgetItem;
    QWidget * widget;
    bool indicator;

public:
    TypeValue(unsigned long long int value);
    QMultiMap<unsigned long long int, LogEvent *> * getChilds();
    void insertChild(LogEvent * value);
    unsigned long long int getValue();
    TypeName * getParent();
    void setParent(TypeName * parent);
    QTreeWidgetItem * getTreeWidgetItem();
    Source * getSource();
    Graph * getGraph();
    bool getIndicator();
};

#endif // TYPEVALUE_H
