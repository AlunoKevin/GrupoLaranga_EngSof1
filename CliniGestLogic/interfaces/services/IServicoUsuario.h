#pragma once
#include "../../models/usuario.h"
#include <QList>

class IServicoUsuario {
public:
    virtual ~IServicoUsuario() = default;
    
    virtual bool atualizarDadosPessoais(int id, const QString& nome, const QString& email) = 0;
    virtual bool alterarSenha(int id, const QString& novaSenha) = 0;
    virtual Usuario* buscarPorId(int id) = 0;
    virtual Usuario* buscarPorLogin(const QString& login) = 0; // Ajuda o Hugo no Login
    virtual Usuario* buscarUtilizadorLogado() = 0;
    virtual void setUsuarioLogado(Usuario* u) = 0;
};