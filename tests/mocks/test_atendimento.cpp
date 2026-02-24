#include "test_atendimento.h"

bool TestAtendimento::executarAtendimentoValido() {
    MockAtendimentoRepository repo;
    ServicoAtendimento servico(&repo);
    
    Atendimento a(1, "Gripe comum", "Repouso e hidratação", "", "");
    return servico.registrar(a);
}

bool TestAtendimento::executarAtendimentoSemDiagnostico() {
    MockAtendimentoRepository repo;
    ServicoAtendimento servico(&repo);
    
    Atendimento a(1, "", "Repouso e hidratação", "", "");
    return servico.registrar(a);
}

bool TestAtendimento::executarAtendimentoSemPrescricao() {
    MockAtendimentoRepository repo;
    ServicoAtendimento servico(&repo);
    
    Atendimento a(1, "Gripe comum", "", "", "");
    return servico.registrar(a);
}


void TestAtendimento::registrar_atendimento_valido() {
    QVERIFY(executarAtendimentoValido());
}

void TestAtendimento::registrar_atendimento_sem_diagnostico() {
    QVERIFY(!executarAtendimentoSemDiagnostico());
}

void TestAtendimento::registrar_atendimento_sem_prescricao() {
    QVERIFY(!executarAtendimentoSemPrescricao());
}