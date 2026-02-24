#ifndef SQLUSUARIOREPOSITORY_H
#define SQLUSUARIOREPOSITORY_H

#include "../../CliniGestLogic/interfaces/repositories/IUsuarioRepository.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class SqlUsuarioRepository : public IUsuarioRepository {
public:
    SqlUsuarioRepository();
    virtual ~SqlUsuarioRepository() = default;

    // Implementação dos métodos da interface
    bool salvar(Usuario* usuario) override;
    bool atualizar(Usuario* usuario) override;
    Usuario* buscarPorId(int id) override;
    Usuario* buscarPorLogin(const QString& login) override;
    QList<Usuario*> listarTodos() override;
};

#endif