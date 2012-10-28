#include <QApplication>
#include <QPlastiqueStyle>
#include <QDebug>

#include "mainwindow.h"
#include "graphicsview.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setStyle(new QPlastiqueStyle);

    MainWindow mainWindow;
    GraphicsView graphicsView;
    mainWindow.setCentralWidget(&graphicsView);
    mainWindow.showMaximized();

    return app.exec();
}
