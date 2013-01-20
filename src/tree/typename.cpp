#include "typename.h"

TypeName::TypeName(QString name)
{
    this->name = name;
}

QMap<unsigned long long, TypeValue *> *TypeName::getChilds()
{
    return &childs;
}

TypeValue * TypeName::insertChild(TypeValue *value)
{
    TypeValue * val = *(childs.insert(value->getValue(), value));
    val->setParent(this);
    return val;
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
