#include "servicoagendamento.h"

ServicoAgendamento::ServicoAgendamento(IConsultaRepository* repo)
    : m_repo(repo)
{
}

bool ServicoAgendamento::agendar(const Consulta& consulta)
{
    // A validação de data/hora pode ser feita aqui depois
    return m_repo->salvar(consulta);
}

// Implementação correta para o seu trabalho da UFOP e uso no SQL
bool ServicoAgendamento::cancelar(int id) {
    if (id <= 0) return false;
    
    // Chama o repositório para fazer o UPDATE no banco real ou no Mock
    return m_repo->atualizarStatus(id, "CANCELADO");
}