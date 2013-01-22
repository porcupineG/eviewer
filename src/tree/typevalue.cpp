#include "typevalue.h"

#include <QLabel>

TypeValue::TypeValue(unsigned long long value)
{
    this->value = value;
    treeWidgetItem = new QTreeWidgetItem();
    treeWidgetItem->setText(0, QString::number(value));
    treeWidgetItem->setSizeHint(1, QSize(100, 100));
    source = new Source();
    graph = new Graph();

}

QMultiMap<unsigned long long, LogEvent *> *TypeValue::getChilds()
{
    return &childs;
}

void TypeValue::insertChild(LogEvent * value)
{
    if (value->getType()->getIndicator() == true) {
        graph->appendData(value->getTimestamp(), value->getIndicator());
        indicator = true;
    } else {
        source->addLogEvent(value);
        indicator = false;
    }

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

QTreeWidgetItem * TypeValue::getTreeWidgetItem()
{
    return treeWidgetItem;
}

Source * TypeValue::getSource()
{
    return source;
}

Graph * TypeValue::getGraph()
{
    return graph;
}

bool TypeValue::getIndicator()
{
    return indicator;
}
