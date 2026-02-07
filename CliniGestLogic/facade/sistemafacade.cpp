#include "sistemafacade.h"
#include "../services/servicoagendamento.h"

SistemaFacade::SistemaFacade(IConsultaRepository* consultaRepo)
    : m_consultaRepo(consultaRepo)
{
    m_servicoAgendamento = new ServicoAgendamento(m_consultaRepo);
}

SistemaFacade::~SistemaFacade()
{
    delete m_servicoAgendamento;
}

bool SistemaFacade::agendarConsulta(const Consulta& consulta)
{
    return m_servicoAgendamento->agendar(consulta);
}
