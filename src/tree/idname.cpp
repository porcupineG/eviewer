#include "idname.h"

IdName::IdName(QString name)
{
    this->name = name;
}

QMap<unsigned long long, IdValue *> *IdName::getChilds()
{
    return &childs;
}

void IdName::insertChild(IdValue * value)
{
    childs.insert(value->getValue(), value);
}

QString IdName::getName()
{
    return name;
}

IdValue * IdName::getParent()
{
    return parent;
}

void IdName::setParent(IdValue *parent)
{
    this->parent = parent;
}
