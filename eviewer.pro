CONFIG -= debug_and_release debug
CONFIG += release

QT += declarative

SOURCES += main.cpp \
    mainwindow.cpp \
    statusbar.cpp \
    toolbar.cpp \
    menubar.cpp \
    infodock.cpp \
    groupfiltersdock.cpp

OTHER_FILES += \
    qml/timeline/Timeline.qml \
    qml/timeline/Description.qml \
    qml/Main.qml

HEADERS += \
    mainwindow.h \
    statusbar.h \
    toolbar.h \
    menubar.h \
    infodock.h \
    groupfiltersdock.h

RESOURCES += \
    qml.qrc
