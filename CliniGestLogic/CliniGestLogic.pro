QT -= gui
CONFIG += c++17 shared

TARGET = CliniGestLogic
TEMPLATE = lib

INCLUDEPATH += $$PWD

HEADERS += \
    facade/sistemafacade.h \
    interfaces/services/IServicoAgendamento.h \
    interfaces/repositories/IConsultaRepository.h \
    interfaces/repositories/ITriagemRepository.h \
    models/consulta.h \
    models/triagem.h \
    services/servicoagendamento.h \
    services/servicotriagem.h \
    models/atendimento.h \
    interfaces/repositories/IAtendimentoRepository.h \
    interfaces/services/IServicoAtendimento.h

SOURCES += \
    facade/sistemafacade.cpp \
    services/servicoagendamento.cpp \
    services/servicotriagem.cpp
