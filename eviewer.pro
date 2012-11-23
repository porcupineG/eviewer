CONFIG += debug

QT += gui

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
    src/timelinebar.cpp \
    src/metamodel.cpp \
    src/eventscollector.cpp \
    src/groupfilter.cpp \
    src/sourcerow.cpp \
    src/events.cpp \
    src/qcustomplot/qcustomplot.cpp \
    src/infowidget.cpp \
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
    src/graph.h \
    src/source.h \
    src/timelinebar.h \
    src/timeline.h \
    src/metamodel.h \
    src/eventscollector.h \
    src/groupfilter.h \
    src/sourcerow.h \
    src/events.h \
    src/qcustomplot/qcustomplot.h \
    src/infowidget.h \
    src/row.h

RESOURCES += \
    res.qrc

OTHER_FILES += \
    doc/pobicos_log_model_v1.xml
