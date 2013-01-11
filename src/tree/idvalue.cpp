#include "idvalue.h"

IdValue::IdValue(unsigned long long value)
{
    this->value = value;
}

void IdValue::setParent(IdName *parent)
{
    this->parent = parent;
}

IdName *IdValue::getParent()
{
    return parent;
}

void IdValue::setChild(IdName *child)
{
    this->child = child;
}

IdName *IdValue::getChild()
{
    return child;
}

void IdValue::insertChild(LevelName *child)
{
    childs.insert(child->getName(), child);
}

QMap<QString, LevelName *> *IdValue::getChilds()
{
    return &childs;
}

unsigned long long IdValue::getValue()
{
    return value;
}
