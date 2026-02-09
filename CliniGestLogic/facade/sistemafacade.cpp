#include "sistemafacade.h"
#include "../services/servicoagendamento.h"
#include "../services/servicotriagem.h"

SistemaFacade::SistemaFacade(IConsultaRepository* consultaRepo, ITriagemRepository* triagemRepo)
    : m_consultaRepo(consultaRepo), m_triagemRepo(triagemRepo)
{
    m_servicoAgendamento = new ServicoAgendamento(m_consultaRepo);
    m_servicoTriagem = new ServicoTriagem(m_triagemRepo);
}

SistemaFacade::~SistemaFacade()
{
    delete m_servicoAgendamento;
    delete m_servicoTriagem;
}

bool SistemaFacade::agendarConsulta(const Consulta& consulta)
{
    return m_servicoAgendamento->agendar(consulta);
}

bool SistemaFacade::registrarTriagem(const Triagem& triagem)
{
    return m_servicoTriagem->registrarTriagem(triagem);
}

bool SistemaFacade::cancelarConsulta(int id) {
    return m_consultaRepo->atualizarStatus(id, "CANCELADO");
}