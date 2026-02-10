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
<<<<<<< Updated upstream
    repositories/SqlTriagemRepository.h \
    repositories/SqlAtendimentoRepository.h

SOURCES += \
    databasemanager/databasemanager.cpp \
    repositories/SqlConsultaRepository.cpp
    # Se você criou um arquivo .cpp para o Atendimento, descomente a linha abaixo:
    # repositories/SqlAtendimentoRepository.cpp
=======
    repositories/SqlTriagemRepository.h

SOURCES += \
    databasemanager/databasemanager.cpp \
    repositories/SqlConsultaRepository.cpp \
    repositories/SqlTriagemRepository.cpp
>>>>>>> Stashed changes
