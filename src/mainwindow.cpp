#include "mainwindow.h"

#include "source.h"

#include "metamodel.h"

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




    //----------------------------------------


    MetaModel metaModel;

    qDebug() << "parse model" << metaModel.setModel("pobicos_log_model_v2.xml");
    qDebug() << "parse data" << metaModel.parse("log_file_2012_10_31");

    QSet<unsigned int> types;

    for (int i = 0; i < metaModel.getEvents()->size(); ++i) {
       types.insert((*metaModel.getEvents())[i].getType()->getValue());
    }

    foreach (unsigned int v, types) {
        Source  * source = new Source();

        for (int i = 0; i < metaModel.getEvents()->size(); ++i) {
            if ((*metaModel.getEvents())[i].getType()->getValue() == v) {
                source->addTimestamp((*metaModel.getEvents())[i].getTimestamp());
            }
        }

        timeline.addSource(source);
    }

//    for (int j = 1; j < 12; j++) {
//        Source  * source = new Source();
//        for (int i = 0; i < 10; i++) {
//            source->addTimestamp(i * i * j);
//        }
//        timeline.addSource(source);
//    }

//    for (int j = 1; j < 5; j++) {
//        Graph  * graph = new Graph();
//        QVector<double> x, y;
//        for (int i = 0; i < 1000; i++) {
//            x.append(i);
//            y.append(qSin(i / 100));
//        }

//        graph->addData(x, y);
//        timeline.addGraph(graph);
//    }

    timeline.update();
    timeline.update();

}

