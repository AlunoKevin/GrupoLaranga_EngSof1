#include <QtTest/QtTest>
#include "servicoagendamento.h"

class TestAgendamento : public QObject
{
    Q_OBJECT

private slots:
    void test_agendarConsulta();
};

void TestAgendamento::test_agendarConsulta()
{
    ServicoAgendamento servico;

    // GIVEN: horário livre
    int pacienteId = 1;
    int medicoId = 1;

    // WHEN: agendo a consulta
    bool resultado = servico.agendar(pacienteId, medicoId);

    // THEN: status deve ser verdadeiro
    QVERIFY(resultado);
}

QTEST_MAIN(TestAgendamento)
#include "test_agendamento.moc"
