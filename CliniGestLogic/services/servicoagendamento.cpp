#include "servicoagendamento.h"
#include <QDate>

ServicoAgendamento::ServicoAgendamento(IConsultaRepository* repo)
    : m_repo(repo)
{
}

bool ServicoAgendamento::agendar(const Consulta& consulta)
{
    if (consulta.getPaciente().empty()) {
        return false;
    }

    if (consulta.getMedico().empty()) {
        return false;
    }

    if (consulta.getData() < QDate::currentDate()) {
        return false;
    }

    if (m_repo) {
        QList<Consulta> consultasDoDia = m_repo->listarPorData(consulta.getData());
        
        for (const Consulta& c : consultasDoDia) {
            if (c.getHorario() == consulta.getHorario() && c.getMedico() == consulta.getMedico()) {
                return false;
            }
        }
        
        return m_repo->salvar(consulta);
    }

    return false;
}

// Implementação correta para o seu trabalho da UFOP e uso no SQL
bool ServicoAgendamento::cancelar(int id) {
    if (id <= 0) return false;
    
    // Chama o repositório para fazer o UPDATE no banco real ou no Mock
    return m_repo->atualizarStatus(id, "CANCELADO");
}