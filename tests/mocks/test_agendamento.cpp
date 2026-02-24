#include "test_agendamento.h"

// Implementação dos Helpers
bool TestAgendamento::executarAgendamentoValido() {
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);
    Consulta c(1, "Paciente Teste", "Medico Teste", QDate::currentDate().addDays(1), QTime(10,0));
    return servico.agendar(c);
}

bool TestAgendamento::executarAgendamentoHorarioOcupado() {
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);
    QDate data = QDate::currentDate().addDays(1);
    QTime hora(10,0);
    Consulta c1(1, "Paciente 1", "Medico 1", data, hora);
    Consulta c2(2, "Paciente 2", "Medico 1", data, hora);
    servico.agendar(c1); 
    return servico.agendar(c2); 
}

bool TestAgendamento::executarAgendamentoSemPaciente() {
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);
    Consulta c(1, "", "Medico Teste", QDate::currentDate().addDays(1), QTime(11,0));
    return servico.agendar(c);
}

bool TestAgendamento::executarAgendamentoSemMedico() {
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);
    Consulta c(1, "Paciente Teste", "", QDate::currentDate().addDays(1), QTime(12,0));
    return servico.agendar(c);
}

bool TestAgendamento::executarAgendamentoDataPassada() {
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);
    Consulta c(1, "Paciente Teste", "Medico Teste", QDate::currentDate().addDays(-1), QTime(9,0));
    return servico.agendar(c);
}

bool TestAgendamento::executarCancelamentoValido() {
    MockConsultaRepository repo;
    ServicoAgendamento servico(&repo);
    int idConsulta = 1;
    return servico.cancelar(idConsulta);
}

void TestAgendamento::cancelar_consulta_existente() {
    QVERIFY(executarCancelamentoValido());
}

void TestAgendamento::agendar_com_horario_livre() {
    QVERIFY(executarAgendamentoValido());
}

void TestAgendamento::agendar_com_horario_ocupado() {
    QVERIFY(!executarAgendamentoHorarioOcupado());
}

void TestAgendamento::agendar_sem_paciente() {
    QVERIFY(!executarAgendamentoSemPaciente());
}

void TestAgendamento::agendar_sem_medico() {
    QVERIFY(!executarAgendamentoSemMedico());
}

void TestAgendamento::agendar_data_passada() {
    QVERIFY(!executarAgendamentoDataPassada());
}