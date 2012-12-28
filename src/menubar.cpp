#include "menubar.h"

MenuBar::MenuBar(QWidget *parent) :
    QMenuBar(parent)
{
    QMenu * file = addMenu(tr("File"));

    QAction * loadModel = file->addAction(tr("Load Model File"));
    QAction * loadLog = file->addAction(tr("Load Log File"));

}
