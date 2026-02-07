#include <QtTest>
#include "mocks/MockConsultaRepository.h"
#include "../CliniGestLogic/services/servicoagendamento.h"

class TestAgendamento : public QObject
{
    Q_OBJECT

private slots:
    void agendar_com_horario_livre();
};

void TestAgendamento::agendar_com_horario_livre()
{
    // GIVEN
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);

    Consulta c(QDate::currentDate(), QTime(10,0));

    // WHEN
    bool resultado = servico.agendar(c);

    // THEN
    QVERIFY(resultado);
}

QTEST_MAIN(TestAgendamento)
#include "test_agendamento.moc"
