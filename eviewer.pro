CONFIG -= debug_and_release debug
CONFIG += release

QT += declarative

SOURCES += main.cpp \
    mainwindow.cpp \
    statusbar.cpp \
    toolbar.cpp \
    menubar.cpp \
    infodock.cpp \
    groupfiltersdock.cpp \
    settingsdock.cpp \
    declarativeview.cpp

OTHER_FILES += \
    qml/timeline/Timeline.qml \
    qml/events/Events.qml \
    qml/events/Source.qml \
    qml/Main.qml \
    qml/core.js

HEADERS += \
    mainwindow.h \
    statusbar.h \
    toolbar.h \
    menubar.h \
    infodock.h \
    groupfiltersdock.h \
    settingsdock.h \
    declarativeview.h

RESOURCES += \
    res.qrc
