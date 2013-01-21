#ifndef IDNAME_H
#define IDNAME_H

#include <QMap>

#include "idvalue.h"
#include "idname.h"
#include "levelname.h"
#include "typename.h"
#include "typevalue.h"
#include "../metamodel/event.h"

#include <QTreeWidgetItem>

class IdValue;

class IdName
{

private:
    IdValue * parent;
    QMap<unsigned long long int, IdValue *> childs;
    QString name;
    QTreeWidgetItem * treeWidgetItem;

public:
    IdName(QString name);

    QMap<unsigned long long int, IdValue *> * getChilds();
    IdValue * insertChild(IdValue * value);
    QString getName();
    IdValue * getParent();
    void setParent(IdValue * parent);

    QTreeWidgetItem * getTreeWidgetItem();
};

#endif // IDNAME_H
