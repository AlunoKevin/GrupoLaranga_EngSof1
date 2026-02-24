QT += core gui testlib
CONFIG += c++17

SOURCES += \
    main.cpp \
    ../../CliniGestLogic/services/servicoagendamento.cpp \
    ../../CliniGestLogic/services/servicotriagem.cpp \
    ../../CliniGestLogic/services/servicousuario.cpp \
    ../../CliniGestLogic/services/servicoatendimento.cpp \
    test_agendamento.cpp \
    test_triagem.cpp \
    test_manter_usuario.cpp \
    test_atendimento.cpp

HEADERS += \
    MockConsultaRepository.h \
    MockTriagemRepository.h \
    MockUsuarioRepository.h \
<<<<<<< HEAD
    MockAtendimentoRepository.h \
    test_agendamento.h \
    test_triagem.h \
    test_manter_usuario.h \
    test_atendimento.h
=======
    test_agendamento.h \
    test_triagem.h \
    test_manter_usuario.h 
>>>>>>> 6d809560c5ad5c9d4529d4963714b60c36f8dffb

INCLUDEPATH += . \
    ../../CliniGestLogic \
    ../../CliniGestData