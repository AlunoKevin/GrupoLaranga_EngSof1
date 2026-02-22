#ifndef IUSUARIOREPOSITORY_H
#define IUSUARIOREPOSITORY_H

#include "../../models/usuario.h"
#include <QList>

class IUsuarioRepository {
public:
    virtual ~IUsuarioRepository() = default;

    virtual bool salvar(Usuario* usuario) = 0;
    virtual bool atualizar(Usuario* usuario) = 0;
    virtual Usuario* buscarPorId(int id) = 0;
    virtual Usuario* buscarPorLogin(const QString& login) = 0;
    virtual QList<Usuario*> listarTodos() = 0;
};

#endif