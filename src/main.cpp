#include <QApplication>
#include <QPlastiqueStyle>
#include <QDebug>

#include "mainwindow.h"
#include "timeline.h"

#include "metamodel.h"


#include <iostream>

int main(int argc, char * argv[]) {

    MetaModel metaModel;

    qDebug() << "parse model" << metaModel.setModel("pobicos_log_model_v2.xml");
    qDebug() << "parse data" << metaModel.parse("log_file_2012_10_31");

    for (int i = 0; i < metaModel.getEvents().size(); ++i) {
//        qDebug() << metaModel.getEvents()[i].getTimestamp();
    }

    //    Level l0 = metaModel.getCpuAndNetwork();
//    Level l1 = metaModel.getRuntimeEnvironment();
//    Level l2 = metaModel.getProcess();
//    Level l3 = metaModel.getApplicationComponent();

//    metaModel.printLevel(&l0);
//    metaModel.printLevel(&l1);
//    metaModel.printLevel(&l2);
//    metaModel.printLevel(&l3);

    return 0;
//    QApplication app(argc, argv);
//    app.setStyle(new QPlastiqueStyle);

//    MainWindow mainWindow;
//    mainWindow.showMaximized();

//    return app.exec();
}
