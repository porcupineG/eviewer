#include <QApplication>
#include <QtDeclarative/QDeclarativeView>
#include <QPlastiqueStyle>

#include "mainwindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    app.setStyle(new QPlastiqueStyle);

    MainWindow mainWindow;
    QDeclarativeView declarativeView;
    declarativeView.setSource(QUrl("qrc:/qml/Main.qml"));
    mainWindow.setCentralWidget(&declarativeView);
    mainWindow.show();

    return app.exec();
}
