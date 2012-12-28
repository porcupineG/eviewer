#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>

#include "toolbar.h"
#include "statusbar.h"
#include "menubar.h"
#include "infodock.h"
#include "groupfiltersdock.h"
#include "settingsdock.h"
#include "timeline.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    StatusBar statusBar;
    ToolBar toolBar;
    MenuBar menuBar;
    Timeline timeline;

    InfoDock infoDock;
    GroupFiltersDock groupFiltersDock;
    SettingsDock settingsDock;

    QAction infoDockAction;
    QAction groupFiltersDockAction;
    QAction settingsDockAction;

    QAction zoomInAction;
    QAction zoomOutAction;

    /* --- */
    MetaModel metaModel;
    /* --- */


public:
    explicit MainWindow(QWidget *parent = 0);
    
signals:
    
public slots:

};

#endif // MAINWINDOW_H
