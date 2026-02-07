#include "servicoagendamento.h"

ServicoAgendamento::ServicoAgendamento(IConsultaRepository* repo)
    : m_repo(repo)
{
}

bool ServicoAgendamento::agendar(const Consulta& consulta)
{
    // validacao dps
    return m_repo->salvar(consulta);
}
