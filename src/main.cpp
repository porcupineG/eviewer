#include <QApplication>
#include <QPlastiqueStyle>
#include <QDebug>

#include "mainwindow.h"
#include "timeline.h"

#include "metamodel.h"



int main(int argc, char * argv[]) {

    MetaModel metaModel;

    qDebug() << metaModel.setModel("pobicos_log_model_v1.xml");
    metaModel.parse("log_file_2012_10_31");

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
