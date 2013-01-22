#include "tree.h"

#include <QPushButton>

Tree::Tree()
{
    root = new IdValue(0);
//    QTreeWidgetItem * topItem = new QTreeWidgetItem();
//    topItem->setText(0, "ROOT");
    treeWidget.insertTopLevelItem(0, root->getTreeWidgetItem());
    treeWidget.setColumnCount(2);

    globalStartTime = ULONG_LONG_MAX;
    globalStopTime = 0;

    millisecPerPixel = 1000;
}

IdName * Tree::getRoot()
{
    return root->getChild();
}

QTreeWidget * Tree::getTreeWidget()
{
    return &treeWidget;
}

void Tree::insert(LogEvent * event)
{
    IdName * parentIdName;
    IdValue * parentIdValue;
    LevelName * parentLevelName;

    parentIdValue = root;

    foreach (Id * id, *(event->getIds())) {
        if (parentIdValue->getChild() == 0) {
            parentIdValue->setChild(new IdName(*id->getName()));
        }
        parentIdName = parentIdValue->getChild();

        IdValue * child = new IdValue(id->getValue());
        parentIdValue = parentIdName->insertChild(child);
        if (child != parentIdValue) {
            delete child;
        }

    }

    LevelName * level = new LevelName(*(event->getSubLevel()->getName()));
    parentLevelName = parentIdValue->insertChild(level);

    TypeName * typeName = parentLevelName->insertChild(new TypeName(*(event->getType()->getName())));

    TypeValue * type = typeName->insertChild(new TypeValue(event->getType()->getValue()));
    type->insertChild(event);
    typeValues.insert(type->getValue(), type);


    // only for testing
    if (event->getType()->getIndicator() == false) {
        if (event->getTimestamp() > globalStopTime) {
            globalStopTime = event->getTimestamp();
        }

        if (event->getTimestamp() < globalStartTime) {
            globalStartTime = event->getTimestamp();
        }
    }

}

void Tree::updateWidgets() {
    if (typeValues.isEmpty() == false) {
        foreach (TypeValue * value, typeValues) {
            if (value->getIndicator() == true) {
                treeWidget.setItemWidget(value->getTreeWidgetItem(), 1, value->getGraph()->getWidget());
            } else {
                treeWidget.setItemWidget(value->getTreeWidgetItem(), 1, value->getSource());
                value->getSource()->setTimeRange(globalStartTime, globalStopTime);
            }
        }
    }

    qDebug() << "global start time" << globalStartTime;

    treeWidget.expandAll();
    sizeUpdate();
}


void Tree::zoomIn()
{
    double frac = millisecPerPixel / 10.0;
    millisecPerPixel -= frac;
    this->sizeUpdate();
}

void Tree::zoomOut()
{
    double frac = millisecPerPixel / 10.0;
    millisecPerPixel += frac;
    this->sizeUpdate();
}

void Tree::sizeUpdate() {
    int w = qRound((globalStopTime - globalStartTime) / millisecPerPixel);
    treeWidget.setColumnWidth(1, w);
    qDebug() << w;
}
