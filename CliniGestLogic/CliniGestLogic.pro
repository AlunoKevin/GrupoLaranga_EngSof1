QT -= gui
CONFIG += c++17 shared

TARGET = CliniGestLogic
TEMPLATE = lib

INCLUDEPATH += $$PWD

HEADERS += \
    facade/sistemafacade.h \
    interfaces/services/IServicoAgendamento.h \
    interfaces/repositories/IConsultaRepository.h \
    models/consulta.h \
    services/servicoagendamento.h

SOURCES += \
    facade/sistemafacade.cpp \
    services/servicoagendamento.cpp \
    services/servicotriagem.cpp

