QT += widgets sql

CONFIG += c++17

TEMPLATE = app
TARGET = CliniGestGUI

INCLUDEPATH += \
    ../CliniGestLogic \
    ../CliniGestData

LIBS += \
    $$PWD/../CliniGestLogic/libCliniGestLogic.so \
    $$PWD/../CliniGestData/libCliniGestData.so

HEADERS += \
    mainwindow.h \
    screens/telaagendamento.h \
    screens/telatriagem.h \
    screens/telaatendimento.h  

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    screens/telaagendamento.cpp \
    screens/telatriagem.cpp \
    screens/telaatendimento.cpp 

FORMS += \
    mainwindow.ui \
    screens/telaagendamento.ui \
    screens/telatriagem.ui \
    screens/telaatendimento.ui  