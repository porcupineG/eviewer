#include "events.h"

#include <QPainter>
#include <QDebug>
#include <QGridLayout>
#include <QLabel>

Events::Events(QWidget * parent) :
    SourceRow(parent)
{
    QGridLayout layout;
    sideWidget.setLayout(&layout);
    layout.addWidget(new QLabel("CHUJ"));

    setFixedHeight(30);
    setFixedWidth(1000);

    QPalette palette;
    palette.setColor(QPalette::Background, Qt::green);
    setAutoFillBackground(true);
    setPalette(palette);

}

void Events::viewInfo(QWidget &widget)
{

}
