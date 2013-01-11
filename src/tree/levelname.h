#ifndef LEVELNAME_H
#define LEVELNAME_H

#include "idvalue.h"
#include "idname.h"
#include "levelname.h"
#include "typename.h"
#include "typevalue.h"
#include "../metamodel/event.h"

class IdValue;
class TypeName;

class LevelName
{
private:
    IdValue * parent;
    QMap<QString, TypeName *> childs;
    QString name;

public:
    LevelName(QString name);

    QMap<QString, TypeName *> * getChilds();
    void insertChild(TypeName * value);
    QString getName();
    IdValue * getParent();
    void setParent(IdValue * parent);

};

#endif // LEVELNAME_H
