QT += widgets sql
CONFIG += c++17

TEMPLATE = app
TARGET = CliniGestGUI

INCLUDEPATH += \
    ../CliniGestLogic \
    ../CliniGestData

# Linkagem das bibliotecas (Mantive o seu formato $$PWD que estava funcionando)
LIBS += \
    $$PWD/../CliniGestLogic/libCliniGestLogic.so \
    $$PWD/../CliniGestData/libCliniGestData.so

# Lista unificada de Headers (Incluindo Atendimento)
HEADERS += \
    mainwindow.h \
    screens/telaagendamento.h \
    screens/telatriagem.h \
    screens/telaatendimento.h \
    ../CliniGestData/repositories/SqlTriagemRepository.h

# Lista unificada de Sources (Incluindo Atendimento)
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    screens/telaagendamento.cpp \
    screens/telatriagem.cpp \
    screens/telaatendimento.cpp \
    ../CliniGestData/repositories/SqlTriagemRepository.cpp

# Lista unificada de Forms (Interfaces Gráficas)
FORMS += \
    mainwindow.ui \
    screens/telaagendamento.ui \
    screens/telatriagem.ui \
    screens/telaatendimento.ui