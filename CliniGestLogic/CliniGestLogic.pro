QT -= gui
CONFIG += c++17 shared

TARGET = CliniGestLogic
TEMPLATE = lib

INCLUDEPATH += $$PWD

HEADERS += \
    facade/sistemafacade.h \
    interfaces/services/IServicoAgendamento.h \
    interfaces/services/IServicoAtendimento.h \
    interfaces/repositories/IConsultaRepository.h \
    interfaces/repositories/ITriagemRepository.h \
    interfaces/repositories/IAtendimentoRepository.h \
    models/consulta.h \
    models/triagem.h \
    models/atendimento.h \
    services/servicoagendamento.h \
    services/servicotriagem.h

SOURCES += \
    facade/sistemafacade.cpp \
    services/servicoagendamento.cpp \
    services/servicotriagem.cpp