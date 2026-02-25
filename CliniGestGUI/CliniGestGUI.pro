QT += core gui widgets sql
CONFIG += c++17

QMAKE_RPATHDIR += ../CliniGestLogic
QMAKE_RPATHDIR += ../CliniGestData

TEMPLATE = app
TARGET = CliniGestGUI

INCLUDEPATH += \
    ../CliniGestLogic \
    ../CliniGestData

# Linkagem das bibliotecas
LIBS += \
    $$PWD/../CliniGestLogic/libCliniGestLogic.so \
    $$PWD/../CliniGestData/libCliniGestData.so

# Lista unificada de Headers (Corrigido com screens/)
HEADERS += \
    mainwindow.h \
    screens/telaagendamento.h \
    screens/telatriagem.h \
    screens/telaatendimento.h \
    screens/telaadminusuarios.h \
    ../CliniGestData/repositories/SqlTriagemRepository.h \
    ../CliniGestData/repositories/SqlUsuarioRepository.h \
    ../CliniGestLogic/services/ServicoUsuario.h \
    screens/telalogin.h \
    screens/telaprincipaladmin.h

# Lista unificada de Sources (Corrigido com screens/)
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    screens/telaagendamento.cpp \
    screens/telatriagem.cpp \
    screens/telaatendimento.cpp \
    screens/telaadminusuarios.cpp \
    ../CliniGestData/repositories/SqlTriagemRepository.cpp \
    ../CliniGestData/repositories/SqlUsuarioRepository.cpp \
    ../CliniGestLogic/services/ServicoUsuario.cpp \
    screens/telalogin.cpp \
    screens/telaprincipaladmin.cpp

# Lista unificada de Forms (Corrigido com screens/)
FORMS += \
    mainwindow.ui \
    screens/telaagendamento.ui \
    screens/telatriagem.ui \
    screens/telaatendimento.ui \
    screens/telaadminusuarios.ui \
    screens/telalogin.ui \
    screens/telaprincipaladmin.ui