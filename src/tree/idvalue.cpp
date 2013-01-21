#include "idvalue.h"

IdValue::IdValue(unsigned long long value) :
    child(0)
{
    this->value = value;
    treeWidgetItem = new QTreeWidgetItem();
    treeWidgetItem->setText(0, QString::number(value));
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

    treeWidgetItem->addChild(child->getTreeWidgetItem());
    child->setParent(this);
}

IdName *IdValue::getChild()
{
    return child;
}

LevelName * IdValue::insertChild(LevelName * child)
{
    LevelName * level;

    QMap<QString, LevelName *>::iterator it = childs.find(child->getName());

    if (it == childs.end()) {
        level = *(childs.insert(child->getName(), child));
    } else {
        level = *it;
    }

    treeWidgetItem->addChild(level->getTreeWidgetItem());
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

QTreeWidgetItem *IdValue::getTreeWidgetItem()
{
    return treeWidgetItem;
}
