#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    infoDock(tr("Information")),
    groupFiltersDock(tr("Group filters")),
    infoDockAction(QIcon(":/icons/24x24/info.png"), tr("Information"), this),
    groupFiltersDockAction(QIcon(":/icons/24x24/search.png"), tr("Group filters"), this)
{
    addToolBar(&toolBar);
    setStatusBar(&statusBar);
    setMenuBar(&menuBar);
    addDockWidget(Qt::RightDockWidgetArea, &infoDock);
    addDockWidget(Qt::RightDockWidgetArea, &groupFiltersDock);

    setContextMenuPolicy(Qt::NoContextMenu);


    toolBar.addAction(&infoDockAction);
    infoDockAction.setCheckable(true);
    connect(&infoDockAction, SIGNAL(toggled(bool)), &infoDock, SLOT(setVisible(bool)));
    connect(&infoDock, SIGNAL(visibilityChanged(bool)), &infoDockAction, SLOT(setChecked(bool)));

    toolBar.addAction(&groupFiltersDockAction);
    groupFiltersDockAction.setCheckable(true);
    connect(&groupFiltersDockAction, SIGNAL(toggled(bool)), &groupFiltersDock, SLOT(setVisible(bool)));
    connect(&groupFiltersDock, SIGNAL(visibilityChanged(bool)), &groupFiltersDockAction, SLOT(setChecked(bool)));

}

