QT += core
CONFIG += c++17 console
CONFIG -= app_bundle

# Seu arquivo principal
SOURCES += main.cpp 

# Arquivos de Lógica e Serviços que serão testados
SOURCES += \
    ../../CliniGestLogic/services/servicoagendamento.cpp \
    ../../CliniGestLogic/services/servicotriagem.cpp \
    ../../CliniGestLogic/services/servicousuario.cpp \
    ../../CliniGestLogic/services/servicoatendimento.cpp \
    ../../CliniGestLogic/facade/sistemafacade.cpp

# Reaproveitando os Mocks da pasta vizinha
HEADERS += \
    ../mocks/MockConsultaRepository.h \
    ../mocks/MockTriagemRepository.h \
    ../mocks/MockUsuarioRepository.h \
    ../mocks/MockAtendimentoRepository.h

# Caminhos de inclusão
INCLUDEPATH += . \
    ../mocks \
    ../../CliniGestLogic \
    ../../CliniGestData