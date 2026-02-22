#include "servicousuario.h"

// No mundo real, isso viria de uma classe 'Sessao' que o Hugo (Login) preenche
static Usuario* usuarioLogadoAtualmente = nullptr; 

ServicoUsuario::ServicoUsuario(IUsuarioRepository* repo) : m_repo(repo) {}

bool ServicoUsuario::atualizarDadosPessoais(int id, const QString& nome, const QString& email) {
    Usuario* u = m_repo->buscarPorId(id);
    if (u) {
        u->setNome(nome);
        u->setEmail(email);
        return m_repo->atualizar(u);
    }
    return false;
}

bool ServicoUsuario::alterarSenha(int id, const QString& novaSenha) {
    Usuario* u = m_repo->buscarPorId(id);
    if (u) {
        // Aqui você chamaria a função de criptografia antes de salvar
        u->setSenha(novaSenha); 
        return m_repo->atualizar(u);
    }
    return false;
}

Usuario* ServicoUsuario::buscarUtilizadorLogado() {
    // Retorna quem o Hugo autenticou no sistema
    return usuarioLogadoAtualmente;
}

// Método auxiliar para o Hugo usar no Login
void ServicoUsuario::setUsuarioLogado(Usuario* u) {
    usuarioLogadoAtualmente = u;
}

Usuario* ServicoUsuario::buscarPorId(int id) {
    return m_repo->buscarPorId(id);
}

Usuario* ServicoUsuario::buscarPorLogin(const QString& login) {
    return m_repo->buscarPorLogin(login);
}