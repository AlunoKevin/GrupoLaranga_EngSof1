QT += sql
CONFIG += c++17 shared

TARGET = CliniGestData
TEMPLATE = lib

INCLUDEPATH += \
    $$PWD \
    ../CliniGestLogic

HEADERS += \
    databasemanager/databasemanager.h \
    repositories/SqlConsultaRepository.h \
    repositories/SqlAtendimentoRepository.h

SOURCES += \
    databasemanager/databasemanager.cpp \
    repositories/SqlConsultaRepository.cpp
