QT += core gui testlib
CONFIG += c++17

# Remova test_agendamento.cpp e test_triagem.cpp daqui!
SOURCES += \
    main.cpp \
    ../../CliniGestLogic/services/servicoagendamento.cpp \
    ../../CliniGestLogic/services/servicotriagem.cpp

HEADERS += \
    MockConsultaRepository.h \
    MockTriagemRepository.h

INCLUDEPATH += . \
    ../../CliniGestLogic \
    ../../CliniGestData