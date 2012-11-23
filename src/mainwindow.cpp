#include "mainwindow.h"

#include "source.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    infoDock(tr("Information")),
    groupFiltersDock(tr("Group filters")),
    settingsDock(tr("Settings")),

    infoDockAction(QIcon(":/icons/24x24/info.png"), tr("Information"), this),
    groupFiltersDockAction(QIcon(":/icons/24x24/search.png"), tr("Group filters"), this),
    settingsDockAction(QIcon(":/icons/24x24/settings.png"), tr("Settings"), this),

    zoomInAction(QIcon(":/icons/24x24/zoom_in.png"), tr("Settings"), this),
    zoomOutAction(QIcon(":/icons/24x24/zoom_out.png"), tr("Settings"), this)

{
    addToolBar(&toolBar);
    setStatusBar(&statusBar);
    setMenuBar(&menuBar);
    toolBar.addSeparator();
    addDockWidget(Qt::RightDockWidgetArea, &infoDock);
    addDockWidget(Qt::RightDockWidgetArea, &groupFiltersDock);
    addDockWidget(Qt::LeftDockWidgetArea, &settingsDock);

    setContextMenuPolicy(Qt::NoContextMenu);

    toolBar.addAction(&infoDockAction);
    infoDockAction.setCheckable(true);
    connect(&infoDockAction, SIGNAL(toggled(bool)), &infoDock, SLOT(setVisible(bool)));
    connect(&infoDock, SIGNAL(visibilityChanged(bool)), &infoDockAction, SLOT(setChecked(bool)));

    toolBar.addAction(&groupFiltersDockAction);
    groupFiltersDockAction.setCheckable(true);
    connect(&groupFiltersDockAction, SIGNAL(toggled(bool)), &groupFiltersDock, SLOT(setVisible(bool)));
    connect(&groupFiltersDock, SIGNAL(visibilityChanged(bool)), &groupFiltersDockAction, SLOT(setChecked(bool)));

    toolBar.addAction(&settingsDockAction);
    settingsDockAction.setCheckable(true);
    connect(&settingsDockAction, SIGNAL(toggled(bool)), &settingsDock, SLOT(setVisible(bool)));
    connect(&settingsDock, SIGNAL(visibilityChanged(bool)), &settingsDockAction, SLOT(setChecked(bool)));

    toolBar.addSeparator();

    toolBar.addAction(&zoomInAction);
    connect(&zoomInAction, SIGNAL(triggered()), &timeline, SLOT(zoomIn()));

    toolBar.addAction(&zoomOutAction);
    connect(&zoomOutAction, SIGNAL(triggered()), &timeline, SLOT(zoomOut()));


    connect(&timeline, SIGNAL(viewInfoWidget(QWidget *)), &infoDock, SLOT(viewInfoWidget(QWidget *)));

    setCentralWidget(&timeline);


    for (int j = 1; j < 12; j++) {
        Source  * source = new Source();
        for (int i = 0; i < 10; i++) {
            source->addTimestamp(i * i * j);
        }
        timeline.addSource(source);
    }
    timeline.update();

}
