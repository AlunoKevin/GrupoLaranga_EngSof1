#include <QCoreApplication>
#include <QDebug>
#include <QDate>
#include <QTime>

#include "MockConsultaRepository.h"
#include "MockTriagemRepository.h"
#include "MockAtendimentoRepository.h"
#include "MockUsuarioRepository.h"
#include "../../CliniGestLogic/services/servicousuario.h"
#include "../../CliniGestLogic/facade/sistemafacade.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "==========================================";
    qDebug() << "   INICIANDO TESTE FUNCIONAL INTEGRADO    ";
    qDebug() << "==========================================";

    MockConsultaRepository mockConsulta;
    MockTriagemRepository mockTriagem;
    MockAtendimentoRepository mockAtendimento;
    MockUsuarioRepository mockUsuario;
    ServicoUsuario mockServicoUsuario(&mockUsuario);

    SistemaFacade facade(&mockConsulta, &mockTriagem, &mockAtendimento, &mockUsuario, &mockServicoUsuario);

    // AGENDAMENTO
    qDebug() << "\n-> ETAPA 1: Agendando consulta...";
    Consulta consulta(1, "João da Silva", "Dra. Juliana", QDate::currentDate(), QTime(14, 0));
    
    if (facade.agendarConsulta(consulta)) {
        qDebug() << "[SUCESSO] Consulta agendada para João da Silva!";
    } else {
        qDebug() << "[ERRO] Falha ao agendar consulta.";
    }

    // TRIAGEM
    qDebug() << "\n-> ETAPA 2: Realizando Triagem...";
    if (facade.verificarPacienteAgendado("João da Silva")) {
        qDebug() << "   Paciente localizado nos agendamentos de hoje. Prosseguindo...";
        
        Triagem triagem("João da Silva", "12/8", 37.5, 75.0, 2); 
        
        if (facade.registrarTriagem(triagem)) {
            qDebug() << "[SUCESSO] Triagem registrada! Paciente pronto para atendimento.";
        }
    } else {
        qDebug() << "[ERRO] Paciente não possui agendamento para hoje.";
    }

    // ATENDIMENTO MÉDICO
    qDebug() << "\n-> ETAPA 3: Atendimento Médico...";
    Atendimento atendimento(1, "Virose leve", "Repouso e hidratação", "Hemograma completo", "Paciente com febre leve");
    
    if (facade.registrarAtendimento(atendimento)) {
        qDebug() << "[SUCESSO] Atendimento registrado com sucesso! Consulta finalizada.";
    } else {
        qDebug() << "[ERRO] Falha ao registrar o atendimento.";
    }

    qDebug() << "\n==========================================";
    qDebug() << "           TESTE FINALIZADO               ";
    qDebug() << "==========================================\n";

    return 0;
}