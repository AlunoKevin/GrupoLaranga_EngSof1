#include "SqlUsuarioRepository.h"
#include <QVariant>
#include <QSqlError>
#include <QDebug>

SqlUsuarioRepository::SqlUsuarioRepository() {
    // A conexão com o banco deve ser garantida pelo DatabaseManager
}

bool SqlUsuarioRepository::salvar(Usuario* usuario) {
    QSqlQuery query;
    query.prepare("INSERT INTO usuarios (nome, cpf, email, login, senha, perfil) "
                  "VALUES (:nome, :cpf, :email, :login, :senha, :perfil)");
    
    query.bindValue(":nome", usuario->getNome());
    query.bindValue(":cpf", usuario->getCpf());
    query.bindValue(":email", usuario->getEmail());
    query.bindValue(":login", usuario->getLogin());
    query.bindValue(":senha", usuario->getSenha());
    query.bindValue(":perfil", usuario->getPerfil());

    if (!query.exec()) {
        qDebug() << "Erro ao salvar usuario:" << query.lastError().text();
        return false;
    }
    return true;
}

bool SqlUsuarioRepository::atualizar(Usuario* usuario) {
    QSqlQuery query;
    query.prepare("UPDATE usuarios SET nome = :nome, email = :email, senha = :senha "
                  "WHERE id = :id");
    
    query.bindValue(":nome", usuario->getNome());
    query.bindValue(":email", usuario->getEmail());
    query.bindValue(":senha", usuario->getSenha());
    query.bindValue(":id", usuario->getId());

    if (!query.exec()) {
        qDebug() << "Erro ao atualizar usuario:" << query.lastError().text();
        return false;
    }
    return true;
}

Usuario* SqlUsuarioRepository::buscarPorLogin(const QString& login) {
    QSqlQuery query;
    query.prepare("SELECT * FROM usuarios WHERE login = :login");
    query.bindValue(":login", login);

    if (query.exec() && query.next()) {
        // Criando o objeto com os dados do banco
        return new Usuario(
            query.value("id").toInt(),
            query.value("nome").toString(),
            query.value("cpf").toString(),
            query.value("email").toString(),
            query.value("login").toString(),
            query.value("senha").toString(),
            query.value("perfil").toString()
        );
    }
    return nullptr;
}

Usuario* SqlUsuarioRepository::buscarPorId(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM usuarios WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return new Usuario(
            query.value("id").toInt(),
            query.value("nome").toString(),
            query.value("cpf").toString(),
            query.value("email").toString(),
            query.value("login").toString(),
            query.value("senha").toString(),
            query.value("perfil").toString()
        );
    }
    return nullptr;
}

QList<Usuario*> SqlUsuarioRepository::listarTodos() {
    QList<Usuario*> lista;
    QSqlQuery query("SELECT * FROM usuarios");

    while (query.next()) {
        lista.append(new Usuario(
            query.value("id").toInt(),
            query.value("nome").toString(),
            query.value("cpf").toString(),
            query.value("email").toString(),
            query.value("login").toString(),
            query.value("senha").toString(),
            query.value("perfil").toString()
        ));
    }
    return lista;
}