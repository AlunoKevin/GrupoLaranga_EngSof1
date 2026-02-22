#ifndef SERVICOUSUARIO_H
#define SERVICOUSUARIO_H

#include "../interfaces/services/IServicoUsuario.h"
#include "../interfaces/repositories/IUsuarioRepository.h"

class ServicoUsuario : public IServicoUsuario {
private:
    IUsuarioRepository* m_repo;

public:
    ServicoUsuario(IUsuarioRepository* repo);
    virtual ~ServicoUsuario() = default;

    // Implementações da interface
    bool atualizarDadosPessoais(int id, const QString& nome, const QString& email) override;
    bool alterarSenha(int id, const QString& novaSenha) override;
    Usuario* buscarPorId(int id) override;
    Usuario* buscarPorLogin(const QString& login) override;
    
    // O método que você precisa para a sua tela
    Usuario* buscarUtilizadorLogado() override;
    
    // Método para o Hugo definir quem logou
    void setUsuarioLogado(Usuario* u) override;
};

#endif