#include "levelname.h"

LevelName::LevelName(QString name)
{
    this->name = name;
    treeWidgetItem = new QTreeWidgetItem();
    treeWidgetItem->setText(0, name);
}

QMap<QString, TypeName *> *LevelName::getChilds()
{
    return &childs;
}

TypeName * LevelName::insertChild(TypeName * value)
{
    TypeName * type;
    QMap<QString, TypeName *>::iterator it = childs.find(value->getName());
    if (it == childs.end()) {
        type = *(childs.insert(value->getName(), value));
    } else {
        type = *it;
    }
    treeWidgetItem->addChild(type->getTreeWidgetItem());
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

QTreeWidgetItem *LevelName::getTreeWidgetItem()
{
    return treeWidgetItem;
}
