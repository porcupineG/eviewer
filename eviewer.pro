CONFIG += debug

QT += gui graphics

SOURCES += main.cpp \
    mainwindow.cpp \
    statusbar.cpp \
    toolbar.cpp \
    menubar.cpp \
    infodock.cpp \
    groupfiltersdock.cpp \
    settingsdock.cpp \
    graphicsview.cpp \
    graph.cpp \
    source.cpp \
    timeline.cpp

HEADERS += \
    mainwindow.h \
    statusbar.h \
    toolbar.h \
    menubar.h \
    infodock.h \
    groupfiltersdock.h \
    settingsdock.h \
    graphicsview.h \
    graph.h \
    source.h \
    timeline.h

RESOURCES += \
    res.qrc
