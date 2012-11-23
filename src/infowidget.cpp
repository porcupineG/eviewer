#include "infowidget.h"

#include <QHeaderView>

InfoWidget::InfoWidget(QWidget *parent) :
    QTreeWidget(parent)
{
    QStringList headers;
    headers.append("Name");
    headers.append("Value");
    headers.append("Units");
    setHeaderLabels(headers);
    addTopLevelItem(new QTreeWidgetItem());
    setAlternatingRowColors(true);
    header()->setResizeMode(QHeaderView::ResizeToContents);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

}

void InfoWidget::setTopLevelName(QString name)
{
    topLevelItem(0)->setText(0, name);
    setItemExpanded(topLevelItem(0), true);
}

void InfoWidget::addLevel(QString levelName)
{
    QTreeWidgetItem * child = new QTreeWidgetItem();
    topLevelItem(0)->addChild(child);
    child->setText(0, levelName);
    setItemExpanded(child, true);
    levels.insert(levelName, topLevelItem(0)->childCount() - 1);
}

void InfoWidget::addSublevel(QString levelName, QString sublevelName, QVariant value, QString units)
{
    QTreeWidgetItem * child = new QTreeWidgetItem();
    topLevelItem(0)->child(levels[levelName])->addChild(child);
    child->setText(0, sublevelName);
    child->setText(1, value.toString());
    child->setText(2, units);

}
