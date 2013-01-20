#include "idvalue.h"

IdValue::IdValue(unsigned long long value) :
    child(0)
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
    if (this->child != 0) {
        delete this->child;
    }

    this->child = child;

    child->setParent(this);
}

IdName *IdValue::getChild()
{
    return child;
}

LevelName * IdValue::insertChild(LevelName * child)
{
    LevelName * level = *(childs.insert(child->getName(), child));
    level->setParent(this);
    return level;
}

QMap<QString, LevelName *> *IdValue::getChilds()
{
    return &childs;
}

unsigned long long IdValue::getValue()
{
    return value;
}
