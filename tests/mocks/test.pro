QT += core gui testlib
CONFIG += c++17

SOURCES += test_agendamento.cpp \
           ../../CliniGestLogic/services/servicoagendamento.cpp

HEADERS += MockConsultaRepository.h \
           MockTriagemRepository.h

INCLUDEPATH += . \
               ../../CliniGestLogic \
               ../../CliniGestData