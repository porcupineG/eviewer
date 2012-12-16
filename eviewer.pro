CONFIG += debug

QT += gui xml

RCC_DIR = ".rcc"
UI_DIR = ".ui"
MOC_DIR = ".moc"
OBJECTS_DIR = ".obj"

CONFIG(debug, debug | release) {
    DESTDIR = "bin/debug"
}
CONFIG(release, debug|release) {
    DESTDIR = "bin/release"
}


SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/statusbar.cpp \
    src/toolbar.cpp \
    src/menubar.cpp \
    src/infodock.cpp \
    src/groupfiltersdock.cpp \
    src/settingsdock.cpp \
    src/timeline.cpp \
    src/graph.cpp \
    src/source.cpp \
    src/metamodel.cpp \
    src/groupfilter.cpp \
    src/qcustomplot.cpp \
    src/infowidget.cpp \
    src/overlay.cpp \
    src/metamodel/level.cpp \
    src/metamodel/sublevel.cpp \
    src/metamodel/logtype.cpp \
    src/metamodel/logcode.cpp \
    src/metamodel/id.cpp \
    src/metamodel/event.cpp \
    src/row.cpp

HEADERS += \
    src/mainwindow.h \
    src/statusbar.h \
    src/toolbar.h \
    src/menubar.h \
    src/infodock.h \
    src/groupfiltersdock.h \
    src/settingsdock.h \
    src/timeline.h \
    src/source.h \
    src/timeline.h \
    src/metamodel.h \
    src/groupfilter.h \
    src/qcustomplot.h \
    src/infowidget.h \
    src/graph.h \
    src/overlay.h \
    src/metamodel/level.h \
    src/metamodel/sublevel.h \
    src/metamodel/logtype.h \
    src/metamodel/logcode.h \
    src/metamodel/id.h \
    src/metamodel/event.h \
    src/row.h

RESOURCES += \
    res.qrc

OTHER_FILES += \
    doc/pobicos_log_model_v1.xml
