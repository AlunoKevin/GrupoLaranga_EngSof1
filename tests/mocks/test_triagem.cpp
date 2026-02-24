#include "test_triagem.h"
#include "../CliniGestLogic/services/servicotriagem.h"
#include "MockTriagemRepository.h"

void TestTriagem::test_registrar_triagem_valida() {
    MockTriagemRepository* mockRepo = new MockTriagemRepository();
    ServicoTriagem servico(mockRepo);
    Triagem t("Paciente Teste", "12/8", 36.5, 70.0, 1);

    QVERIFY(servico.registrarTriagem(t));
    QCOMPARE(mockRepo->triagensSalvas.size(), 1);
    delete mockRepo;
}

void TestTriagem::test_validar_temperatura_perigosa() {
    MockTriagemRepository* mockRepo = new MockTriagemRepository();
    ServicoTriagem servico(mockRepo);
    Triagem t("Paciente Invalido", "12/8", 55.0, 70.0, 4);
    
    QVERIFY(!servico.registrarTriagem(t));
    delete mockRepo;
}