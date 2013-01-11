#include "typename.h"

TypeName::TypeName(QString name)
{
    this->name = name;
}

QMap<unsigned long long, TypeValue *> *TypeName::getChilds()
{
    return &childs;
}

void TypeName::insertChild(TypeValue *value)
{
    childs.insert(value->getValue(), value);
}

QString TypeName::getName()
{
    return name;
}

LevelName *TypeName::getParent()
{
    return parent;
}

void TypeName::setParent(LevelName *parent)
{
    this->parent = parent;
}
