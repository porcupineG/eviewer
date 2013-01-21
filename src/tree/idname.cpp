#include "idname.h"

#include <QDebug>

IdName::IdName(QString name)
{
    this->name = name;
    treeWidgetItem = new QTreeWidgetItem();
    treeWidgetItem->setText(0, name);
}

QMap<unsigned long long, IdValue *> *IdName::getChilds()
{
    return &childs;
}

IdValue * IdName::insertChild(IdValue * value)
{
    qDebug() << "---";
    qDebug() << (unsigned long int) value;

    IdValue * val = *(childs.find(value->getValue()));
    if (childs.find(value->getValue()) == childs.end()) {
        val = *(childs.insert(value->getValue(), value));
    }

    qDebug() << (unsigned long int) val;

    val->setParent(this);
    treeWidgetItem->addChild(val->getTreeWidgetItem());
    return val;
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

QTreeWidgetItem *IdName::getTreeWidgetItem()
{
    return treeWidgetItem;
}
