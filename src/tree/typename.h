#ifndef TYPENAME_H
#define TYPENAME_H

#include "idvalue.h"
#include "idname.h"
#include "levelname.h"
#include "typename.h"
#include "typevalue.h"
#include "../metamodel/event.h"

#include <QTreeWidgetItem>

class LevelName;
class TypeValue;

class TypeName
{
private:
    LevelName * parent;
    QMap<unsigned long long int, TypeValue *> childs;
    QString name;
    QTreeWidgetItem * treeWidgetItem;


public:
    TypeName(QString name);
    QMap<unsigned long long int, TypeValue *> * getChilds();
    TypeValue *insertChild(TypeValue * value);
    QString getName();
    LevelName * getParent();
    void setParent(LevelName * parent);
    QTreeWidgetItem * getTreeWidgetItem();

};

#endif // TYPENAME_H
