#include "levelname.h"

LevelName::LevelName(QString name)
{
    this->name = name;
}

QMap<QString, TypeName *> *LevelName::getChilds()
{
    return &childs;
}

void LevelName::insertChild(TypeName * value)
{
    childs.insert(value->getName(), value);
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
