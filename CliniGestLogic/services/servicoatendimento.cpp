#include "servicoatendimento.h"

ServicoAtendimento::ServicoAtendimento(IAtendimentoRepository* repo) 
    : m_repo(repo) 
{
}

bool ServicoAtendimento::registrar(const Atendimento& atendimento) {
    if (atendimento.diagnostico().trimmed().isEmpty() || 
        atendimento.prescricao().trimmed().isEmpty()) {
        return false; 
    }
    
    if (m_repo) {
        return m_repo->salvar(atendimento);
    }
    
    return false;
}