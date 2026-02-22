#include "sistemafacade.h"

SistemaFacade::SistemaFacade(IConsultaRepository* consultaRepo, 
                             ITriagemRepository* triagemRepo,
                             IAtendimentoRepository* atendimentoRepo,
                             IUsuarioRepository* usuarioRepo,
                             IServicoUsuario* usuarioServico)
    : m_consultaRepo(consultaRepo), 
      m_triagemRepo(triagemRepo),
      m_atendimentoRepo(atendimentoRepo),
      m_usuarioRepo(usuarioRepo),
      m_usuarioServico(usuarioServico)
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

bool SistemaFacade::atualizarDadosUtilizador(int id, const QString& nome, const QString& email) {
    if (m_usuarioServico) {
        return m_usuarioServico->atualizarDadosPessoais(id, nome, email);
    }
    return false;
}

bool SistemaFacade::alterarSenha(int id, const QString& novaSenha) {
    if (m_usuarioServico) {
        return m_usuarioServico->alterarSenha(id, novaSenha);
    }
    return false;
}

Usuario* SistemaFacade::buscarUtilizadorLogado() {
    if (m_usuarioServico) {
        return m_usuarioServico->buscarUtilizadorLogado();
    }
    return nullptr;
}