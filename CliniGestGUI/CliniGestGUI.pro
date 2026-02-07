QT += widgets sql

CONFIG += c++17

TEMPLATE = app
TARGET = CliniGestGUI

INCLUDEPATH += \
    ../CliniGestLogic \
    ../CliniGestData

LIBS += \
    -L../CliniGestLogic -lCliniGestLogic \
    -L../CliniGestData  -lCliniGestData

HEADERS += \
    mainwindow.h

SOURCES += \
    main.cpp \
    mainwindow.cpp

FORMS += \
    mainwindow.ui
