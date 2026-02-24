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

bool SistemaFacade::verificarPacienteAgendado(const QString& nome) {
    QString nomeBusca = nome.trimmed(); 
    
    if (nomeBusca.isEmpty()) {
        return false;
    }

    if (m_consultaRepo) {
        QDate hoje = QDate::currentDate();
        QList<Consulta> consultasHoje = m_consultaRepo->listarPorData(hoje);
        
        for (const Consulta& c : consultasHoje) {
            QString nomePacienteAgendado = QString::fromStdString(c.getPaciente());
            
            if (nomePacienteAgendado.contains(nomeBusca, Qt::CaseInsensitive)) {
                return true;
            }
        }
        return false; 
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

// verificar se o login existe e se a senha bate, se sim, setar o usuário logado no serviço
bool SistemaFacade::autenticar(const QString& login, const QString& senha)
{
    if (!m_usuarioServico)
        return false;

    Usuario* u = m_usuarioServico->buscarPorLogin(login);

    if (u && u->getSenha() == senha) {
        m_usuarioServico->setUsuarioLogado(u);
        return true;
    }

    return false;
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

bool SistemaFacade::cadastrarUsuario(Usuario* usuario)
{
    if (m_usuarioRepo) {
        return m_usuarioRepo->salvar(usuario);
    }
    return false;
}

Usuario* SistemaFacade::buscarUsuarioPorId(int id)
{
    if (m_usuarioServico) {
        return m_usuarioServico->buscarPorId(id);
    }
    return nullptr;
}