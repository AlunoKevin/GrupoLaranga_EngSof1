#include "sistemafacade.h"
#include <QDebug>

SistemaFacade::SistemaFacade(IConsultaRepository* consultaRepo, 
                             ITriagemRepository* triagemRepo,
                             IAtendimentoRepository* atendimentoRepo)
    : m_consultaRepo(consultaRepo), 
      m_triagemRepo(triagemRepo),
      m_atendimentoRepo(atendimentoRepo)
{
}

SistemaFacade::~SistemaFacade()
{
    
}

bool SistemaFacade::agendarConsulta(const Consulta& consulta)
{
    if (m_consultaRepo) {
        return m_consultaRepo->salvar(consulta);
    }
    return false;
}

bool SistemaFacade::verificarPacienteAgendado(const QString& nome) {
    QString nomeBusca = nome.trimmed(); 
    
    if (nomeBusca.isEmpty()) {
        return false;
    }

    if (m_consultaRepo) {
        QDate hoje = QDate::currentDate();
        QList<Consulta> consultasHoje = m_consultaRepo->listarPorData(hoje);
        
        // LOGS PARA DESCOBRIR O MISTÉRIO:
        qDebug() << "=== INICIANDO BUSCA DE PACIENTE ===";
        qDebug() << "Procurando por:" << nomeBusca;
        qDebug() << "Data de hoje (sistema):" << hoje.toString("yyyy-MM-dd");
        qDebug() << "Total de consultas retornadas pelo banco hoje:" << consultasHoje.size();
        
        for (const Consulta& c : consultasHoje) {
            QString nomePacienteAgendado = QString::fromStdString(c.getPaciente());
            qDebug() << " - Encontrado no banco:" << nomePacienteAgendado;
            
            if (nomePacienteAgendado.contains(nomeBusca, Qt::CaseInsensitive)) {
                qDebug() << " >>> MATCH! Paciente encontrado!";
                return true;
            }
        }
        qDebug() << "Nenhum match encontrado no loop.";
        return false; 
    }
    
    qDebug() << "Erro: m_consultaRepo está nulo!";
    return false;
}

bool SistemaFacade::registrarTriagem(const Triagem& triagem)
{
    if (m_triagemRepo) {
        return m_triagemRepo->salvar(triagem);
    }
    return false;
}

bool SistemaFacade::registrarAtendimento(const Atendimento& atendimento)
{
    if (m_atendimentoRepo) {
        return m_atendimentoRepo->salvar(atendimento);
    }
    return false;
}

bool SistemaFacade::autenticar(const QString& usuario, const QString& senha) {
    // Lógica simples para teste 
    return (usuario == "admin" && senha == "1234");
}