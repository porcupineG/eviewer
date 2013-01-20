#include "levelname.h"

LevelName::LevelName(QString name)
{
    this->name = name;
}

QMap<QString, TypeName *> *LevelName::getChilds()
{
    return &childs;
}

TypeName * LevelName::insertChild(TypeName * value)
{
    TypeName * type = *(childs.insert(value->getName(), value));
    type->setParent(this);
    return type;
}

QString LevelName::getName()
{
    return name;
}

IdValue * LevelName::getParent()
{
    return parent;
}

void LevelName::setParent(IdValue *parent)
{
    this->parent = parent;
}
