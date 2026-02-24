#include "servicousuario.h"

ServicoUsuario::ServicoUsuario(IUsuarioRepository* repo) : m_repo(repo), m_usuarioLogado(nullptr) {}

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
    // Retorna a variável oficial da classe
    return m_usuarioLogado;
}

void ServicoUsuario::setUsuarioLogado(Usuario* u) {
    // Guarda o usuário na variável oficial
    m_usuarioLogado = u;
}

Usuario* ServicoUsuario::buscarPorId(int id) {
    return m_repo->buscarPorId(id);
}

Usuario* ServicoUsuario::buscarPorLogin(const QString& login) {
    return m_repo->buscarPorLogin(login);
}

bool ServicoUsuario::autenticar(const QString& login, const QString& senha) {
    // 1. Pede para o banco de dados buscar o usuário com este login
    Usuario* u = buscarPorLogin(login);

    // 2. Verifica se o usuário existe E se a senha digitada bate com a do banco
    if (u != nullptr && u->getSenha() == senha) {
        setUsuarioLogado(u); // Guarda na "sessão" que este usuário está logado
        return true;         // Login aprovado!
    }

    // 3. Se não achou o usuário ou a senha estiver errada
    return false;
}

void ServicoUsuario::logout() {
    // Para deslogar, simplesmente apagamos a referência do usuário logado
    m_usuarioLogado = nullptr;
}