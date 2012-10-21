#include "menubar.h"

MenuBar::MenuBar(QWidget *parent) :
    QMenuBar(parent)
{
    addMenu(tr("File"));
}
