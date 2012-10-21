#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>

#include "toolbar.h"
#include "statusbar.h"
#include "menubar.h"
#include "infodock.h"
#include "groupfiltersdock.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    StatusBar statusBar;
    ToolBar toolBar;
    MenuBar menuBar;

    InfoDock infoDock;
    GroupFiltersDock groupFiltersDock;

    QAction infoDockAction;
    QAction groupFiltersDockAction;


public:
    explicit MainWindow(QWidget *parent = 0);
    
signals:
    
public slots:

};

#endif // MAINWINDOW_H
