#include "typevalue.h"

TypeValue::TypeValue(unsigned long long value)
{
    this->value = value;
}

QMultiMap<unsigned long long, LogEvent *> *TypeValue::getChilds()
{
    return &childs;
}

void TypeValue::insertChild(LogEvent *value)
{
    childs.insert(value->getTimestamp(), value);
}

unsigned long long TypeValue::getValue()
{
    return value;
}

TypeName * TypeValue::getParent()
{
    return parent;
}

void TypeValue::setParent(TypeName *parent)
{
    this->parent = parent;
}
