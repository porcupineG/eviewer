#include <QApplication>
#include <QPlastiqueStyle>

#include "mainwindow.h"
#include "declarativeview.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    app.setStyle(new QPlastiqueStyle);

    MainWindow mainWindow;
    DeclarativeView declarativeView;
    declarativeView.setSource(QUrl("qrc:/qml/Main.qml"));
    declarativeView.setResizeMode(QDeclarativeView::SizeRootObjectToView);
    declarativeView.setAutoFillBackground(true);

    mainWindow.setCentralWidget(&declarativeView);
    mainWindow.showMaximized();

    return app.exec();
}
