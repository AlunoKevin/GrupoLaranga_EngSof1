#include <QtTest>
#include "mocks/MockConsultaRepository.h"
#include "../CliniGestLogic/services/servicoagendamento.h"

class TestAgendamento : public QObject
{
    Q_OBJECT

private:
    // Helper methods
    bool executarAgendamentoValido();
    bool executarAgendamentoHorarioOcupado();
    bool executarAgendamentoSemPaciente();
    bool executarAgendamentoSemMedico();
    bool executarAgendamentoDataPassada();

private slots:
    void agendar_com_horario_livre();
    void agendar_com_horario_ocupado();
    void agendar_sem_paciente();
    void agendar_sem_medico();
    void agendar_data_passada();
};

//
// Helper implementations
//

bool TestAgendamento::executarAgendamentoValido()
{
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);

    Consulta c(QDate::currentDate().addDays(1), QTime(10,0));
    return servico.agendar(c);
}

bool TestAgendamento::executarAgendamentoHorarioOcupado()
{
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);

    QDate data = QDate::currentDate().addDays(1);
    QTime hora(10,0);

    Consulta c1(data, hora);
    Consulta c2(data, hora);

    servico.agendar(c1);           // first one occupies the slot
    return servico.agendar(c2);    // should fail
}

bool TestAgendamento::executarAgendamentoSemPaciente()
{
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);

    Consulta c(QDate::currentDate().addDays(1), QTime(11,0));
    c.setPaciente("");   // assuming string or invalid value

    return servico.agendar(c);
}

bool TestAgendamento::executarAgendamentoSemMedico()
{
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);

    Consulta c(QDate::currentDate().addDays(1), QTime(12,0));
    c.setMedico("");   // assuming string or invalid value

    return servico.agendar(c);
}

bool TestAgendamento::executarAgendamentoDataPassada()
{
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);

    Consulta c(QDate::currentDate().addDays(-1), QTime(9,0));
    return servico.agendar(c);
}

//
// Test slots
//

void TestAgendamento::agendar_com_horario_livre()
{
    QVERIFY(executarAgendamentoValido());
}

void TestAgendamento::agendar_com_horario_ocupado()
{
    QVERIFY(!executarAgendamentoHorarioOcupado());
}

void TestAgendamento::agendar_sem_paciente()
{
    QVERIFY(!executarAgendamentoSemPaciente());
}

void TestAgendamento::agendar_sem_medico()
{
    QVERIFY(!executarAgendamentoSemMedico());
}

void TestAgendamento::agendar_data_passada()
{
    QVERIFY(!executarAgendamentoDataPassada());
}

QTEST_MAIN(TestAgendamento)
#include "test_agendamento.moc"
