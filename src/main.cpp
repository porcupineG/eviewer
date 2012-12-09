#include <QApplication>
#include <QPlastiqueStyle>
#include <QDebug>

#include "mainwindow.h"
#include "timeline.h"

#include "metamodel.h"


#include <iostream>

int main(int argc, char * argv[]) {
    QApplication app(argc, argv);
    app.setStyle(new QPlastiqueStyle);

    MainWindow mainWindow;
    mainWindow.showMaximized();

    return app.exec();
}
