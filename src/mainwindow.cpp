#include "mainwindow.h"

#include "source.h"

#include "metamodel.h"

#include <QFileDialog>
#include <QMessageBox>

MainWindow::
MainWindow(QWidget *parent) :
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

    connect(&menuBar, SIGNAL(triggered(QAction*)), this, SLOT(action(QAction*)));

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

//    setCentralWidget(&timeline);


    //----------------------------------------


    qDebug() << "model" << metaModel.setModel("pobicos_log_model_v2.xml");
    qDebug() << "parse" << metaModel.parse("log_file_2012_12_07");

    tree = metaModel.getTree();
    setCentralWidget(tree->getTreeWidget());
    tree->updateWidgets();

   connect(&zoomOutAction, SIGNAL(triggered()), this, SLOT(zoomOut()));
   connect(&zoomInAction, SIGNAL(triggered()), this, SLOT(zoomIn()));

//    updateSources();
}

void MainWindow::action(QAction * action)
{
    if (action->text() == "Load Model File") {
        QString  fileName = QFileDialog::getOpenFileName(this, tr("Open Model File"), "./", tr("Model Files (*.xml)"));
        if (metaModel.setModel(fileName) == true) {
            QMessageBox msg;
            msg.setText("Model File read correctly.");
            msg.exec();
        } else {
            QMessageBox msg;
            msg.setText("Model File read failed.");
            msg.exec();
        }
    }

    if (action->text() == "Load Log File") {
        QString  fileName = QFileDialog::getOpenFileName(this, tr("Open Log File"), "./", tr("Log Files"));
        if (metaModel.parse(fileName) == true) {
            QMessageBox msg;
            msg.setText("Log File read correctly.");
            msg.exec();

            updateSources();

        } else {
            QMessageBox msg;
            msg.setText("Log File read failed.");
            msg.exec();
        }

    }

}

void MainWindow::zoomIn()
{

    tree->zoomIn();
}

void MainWindow::zoomOut()
{
    tree->zoomOut();
}

void MainWindow::updateSources() {
    Source  * cpuAndNetwork = new Source();
    for (int i = 0; i < metaModel.getEvents()->size(); ++i) {
        cpuAndNetwork->addLogEvent((*metaModel.getEvents())[i]);
        cpuAndNetwork->setName("Cpu And Network");
    }
    timeline.addSource(cpuAndNetwork);


    Source  * runtimeEnvironment = new Source();
    for (int i = 0; i < metaModel.getEvents()->size(); ++i) {
        runtimeEnvironment->addLogEvent((*metaModel.getEvents())[i]);
        runtimeEnvironment->setName("Runtime environment");
    }
    timeline.addSource(runtimeEnvironment);

    Source  * process = new Source();
    for (int i = 0; i < metaModel.getEvents()->size(); ++i) {
        process->addLogEvent((*metaModel.getEvents())[i]);
        process->setName("Process");
    }
    timeline.addSource(process);

    Source  * applicationComponent = new Source();
    for (int i = 0; i < metaModel.getEvents()->size(); ++i) {
        applicationComponent->addLogEvent((*metaModel.getEvents())[i]);
        applicationComponent->setName("Application Component");
    }
    timeline.addSource(applicationComponent);



    timeline.update();
}
