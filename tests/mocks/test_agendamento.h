#ifndef TEST_AGENDAMENTO_H
#define TEST_AGENDAMENTO_H

#include <QObject>
#include <QtTest>
#include "MockConsultaRepository.h"
#include "../../CliniGestLogic/services/servicoagendamento.h"

class TestAgendamento : public QObject
{
    Q_OBJECT

private:
    bool executarAgendamentoValido();
    bool executarAgendamentoHorarioOcupado();
    bool executarAgendamentoSemPaciente();
    bool executarAgendamentoSemMedico();
    bool executarAgendamentoDataPassada();
    bool executarCancelamentoValido();

private slots:
    void agendar_com_horario_livre();
    void agendar_com_horario_ocupado();
    void agendar_sem_paciente();
    void agendar_sem_medico();
    void agendar_data_passada();
    void cancelar_consulta_existente();
};

#endif // TEST_AGENDAMENTO_H