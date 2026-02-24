#ifndef SERVICOUSUARIO_H
#define SERVICOUSUARIO_H

#include "../interfaces/services/IServicoUsuario.h"
#include "../interfaces/repositories/IUsuarioRepository.h"

class ServicoUsuario : public IServicoUsuario {
private:
    IUsuarioRepository* m_repo;
    
    Usuario* m_usuarioLogado; 

public:
    ServicoUsuario(IUsuarioRepository* repo);
    virtual ~ServicoUsuario() = default;

    bool atualizarDadosPessoais(int id, const QString& nome, const QString& email) override;
    bool alterarSenha(int id, const QString& novaSenha) override;
    Usuario* buscarPorId(int id) override;
    Usuario* buscarPorLogin(const QString& login) override;
    
    Usuario* buscarUtilizadorLogado() override;
    
    void setUsuarioLogado(Usuario* u) override;

    bool autenticar(const QString& login, const QString& senha) override;
    void logout() override;
};

#endif