QT += widgets sql
CONFIG += c++17

TEMPLATE = app
TARGET = CliniGestGUI

# Garante que ele busque os headers nas outras pastas
INCLUDEPATH += \
    ../CliniGestLogic \
    ../CliniGestData

# Link das bibliotecas (formato Linux padrão)
LIBS += -L../CliniGestLogic -lCliniGestLogic
LIBS += -L../CliniGestData -lCliniGestData

# Certifique-se de que o main.cpp está aqui!
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    screens/telaagendamento.cpp \
    screens/telatriagem.cpp

HEADERS += \
    mainwindow.h \
    screens/telaagendamento.h \
    screens/telatriagem.h

FORMS += \
    mainwindow.ui \
    screens/telaagendamento.ui \
    screens/telatriagem.ui