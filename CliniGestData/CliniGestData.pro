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
    repositories/SqlTriagemRepository.h \
    repositories/SqlAtendimentoRepository.h \
    repositories/SqlUsuarioRepository.h

SOURCES += \
    databasemanager/databasemanager.cpp \
    repositories/SqlConsultaRepository.cpp \
    repositories/SqlTriagemRepository.cpp \
    # Se você criou um arquivo .cpp para o Atendimento, descomente a linha abaixo:
    # repositories/SqlAtendimentoRepository.cpp
    repositories/SqlUsuarioRepository.cpp
