QT += core gui testlib
CONFIG += c++17

SOURCES += \
    main.cpp \
    ../../CliniGestLogic/services/servicoagendamento.cpp \
    ../../CliniGestLogic/services/servicotriagem.cpp \
    ../../CliniGestLogic/services/servicousuario.cpp \
    test_agendamento.cpp \
    test_triagem.cpp \
    test_manter_usuario.cpp

HEADERS += \
    MockConsultaRepository.h \
    MockTriagemRepository.h \
    MockUsuarioRepository.h \
    test_agendamento.h \
    test_triagem.h \
    test_manter_usuario.h 

INCLUDEPATH += . \
    ../../CliniGestLogic \
    ../../CliniGestData