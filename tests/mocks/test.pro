QT += testlib
QT -= gui
CONFIG += c++17 console

TEMPLATE = app
TARGET = CliniGestTests

INCLUDEPATH += \
    ../CliniGestLogic

HEADERS += \
    mocks/MockConsultaRepository.h

SOURCES += \
    test_agendamento.cpp
