#ifndef LEVELNAME_H
#define LEVELNAME_H

#include "idvalue.h"
#include "idname.h"
#include "levelname.h"
#include "typename.h"
#include "typevalue.h"
#include "../metamodel/event.h"

#include <QTreeWidgetItem>

class IdValue;
class TypeName;

class LevelName
{
private:
    IdValue * parent;
    QMap<QString, TypeName *> childs;
    QString name;
    QTreeWidgetItem * treeWidgetItem;


public:
    LevelName(QString name);

    QMap<QString, TypeName *> * getChilds();
    TypeName * insertChild(TypeName * value);
    QString getName();
    IdValue * getParent();
    void setParent(IdValue * parent);
    QTreeWidgetItem * getTreeWidgetItem();


};

#endif // LEVELNAME_H
