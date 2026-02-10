QT += core gui testlib
CONFIG += c++17

SOURCES += \
    test_agendamento.cpp \
    test_triagem.cpp \
    main.cpp \ 
    ../../CliniGestLogic/services/servicoagendamento.cpp \
    ../../CliniGestLogic/services/servicotriagem.cpp

HEADERS += MockConsultaRepository.h \
           MockTriagemRepository.h

INCLUDEPATH += . \
               ../../CliniGestLogic \
               ../../CliniGestData