QT += core gui testlib
CONFIG += c++17

SOURCES += \
    main.cpp \
    ../../CliniGestLogic/services/servicoagendamento.cpp \
    ../../CliniGestLogic/services/servicotriagem.cpp \
    ../../CliniGestLogic/services/servicousuario.cpp

HEADERS += \
    MockConsultaRepository.h \
    MockTriagemRepository.h \
    MockUsuarioRepository.h \
    test_manter_usuario.cpp  

INCLUDEPATH += . \
    ../../CliniGestLogic \
    ../../CliniGestData