#include "sistemafacade.h"
#include "../services/servicoagendamento.h"
#include "../services/servicotriagem.h"

SistemaFacade::SistemaFacade(IConsultaRepository* consultaRepo, 
                               ITriagemRepository* triagemRepo,
                               IAtendimentoRepository* atendimentoRepo)
    : m_consultaRepo(consultaRepo), 
      m_triagemRepo(triagemRepo),
      m_atendimentoRepo(atendimentoRepo)
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

bool SistemaFacade::autenticar(const QString& usuario, const QString& senha) {
    return (usuario == "admin" && senha == "1234");
}

bool SistemaFacade::registrarAtendimento(const Atendimento& atendimento) {
    if (m_atendimentoRepo) {
        return m_atendimentoRepo->salvar(atendimento);
    }
    return false;
}