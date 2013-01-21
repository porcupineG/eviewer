#include "typename.h"

TypeName::TypeName(QString name)
{
    this->name = name;
    treeWidgetItem = new QTreeWidgetItem();
    treeWidgetItem->setText(0, name);
}

QMap<unsigned long long, TypeValue *> *TypeName::getChilds()
{
    return &childs;
}

TypeValue * TypeName::insertChild(TypeValue *value)
{
    TypeValue * val;

    QMap<unsigned long long int, TypeValue *>::iterator it = childs.find(value->getValue());
    if (it == childs.end()) {
        val = *(childs.insert(value->getValue(), value));
    } else {
        val = *it;
    }

    treeWidgetItem->addChild(val->getTreeWidgetItem());
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

QTreeWidgetItem *TypeName::getTreeWidgetItem()
{
    return treeWidgetItem;
}
