#include "toolbar.h"

ToolBar::ToolBar(QWidget *parent) :
    QToolBar(parent)
{
    setFloatable(false);
    setMovable(false);
}

