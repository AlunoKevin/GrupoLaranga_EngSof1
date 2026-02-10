#include <QtTest>
#include "MockConsultaRepository.h"
#include "../../CliniGestLogic/services/servicoagendamento.h"

class TestAgendamento : public QObject
{
    Q_OBJECT

private:
    // Helper methods para organizar o código
    bool executarAgendamentoValido();
    bool executarAgendamentoHorarioOcupado();
    bool executarAgendamentoSemPaciente();
    bool executarAgendamentoSemMedico();
    bool executarAgendamentoDataPassada();
    bool executarCancelamentoValido();

private slots:
    // Os testes que o Qt vai rodar
    void agendar_com_horario_livre();
    void agendar_com_horario_ocupado();
    void agendar_sem_paciente();
    void agendar_sem_medico();
    void agendar_data_passada();
    void cancelar_consulta_existente(); // Teste da sua parte
};

//
// Implementação dos Helpers (Criação dos cenários)
//

bool TestAgendamento::executarAgendamentoValido()
{
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);

    Consulta c(1, "Paciente Teste", "Medico Teste", QDate::currentDate().addDays(1), QTime(10,0));
    return servico.agendar(c);
}

bool TestAgendamento::executarAgendamentoHorarioOcupado()
{
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);

    QDate data = QDate::currentDate().addDays(1);
    QTime hora(10,0);

    Consulta c1(1, "Paciente 1", "Medico 1", data, hora);
    Consulta c2(2, "Paciente 2", "Medico 1", data, hora);

    servico.agendar(c1); 
    return servico.agendar(c2); // Deve falhar se a lógica de ocupado estiver pronta
}

bool TestAgendamento::executarAgendamentoSemPaciente()
{
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);

    Consulta c(1, "", "Medico Teste", QDate::currentDate().addDays(1), QTime(11,0));
    return servico.agendar(c);
}

bool TestAgendamento::executarAgendamentoSemMedico()
{
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);

    // Corrigido: Passando nome vazio para o médico
    Consulta c(1, "Paciente Teste", "", QDate::currentDate().addDays(1), QTime(12,0));
    return servico.agendar(c);
}

bool TestAgendamento::executarAgendamentoDataPassada()
{
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);

    // Corrigido: Usando data de ontem
    Consulta c(1, "Paciente Teste", "Medico Teste", QDate::currentDate().addDays(-1), QTime(9,0));
    return servico.agendar(c);
}

bool TestAgendamento::executarCancelamentoValido()
{
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);

    int idConsulta = 1;
    // Chama o método cancelar que você criou no serviço
    return servico.cancelar(idConsulta);
}

//
// Slots de Teste (Onde as verificações acontecem)
//

void TestAgendamento::cancelar_consulta_existente()
{
    QVERIFY(executarCancelamentoValido());
}

void TestAgendamento::agendar_com_horario_livre()
{
    QVERIFY(executarAgendamentoValido());
}

void TestAgendamento::agendar_com_horario_ocupado()
{
    // Esperamos que retorne FALSE (!), pois o horário já está ocupado
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

// QTEST_MAIN(TestAgendamento)
#include "test_agendamento.moc"