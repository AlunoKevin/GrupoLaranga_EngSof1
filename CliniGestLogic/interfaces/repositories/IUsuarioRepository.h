#ifndef IUSUARIOREPOSITORY_H
#define IUSUARIOREPOSITORY_H

#include "../../models/usuario.h"
#include <QList>

/**
 * @interface IUsuarioRepository
 * @brief Interface para persistência e manipulação de dados de usuários no sistema.
 */
class IUsuarioRepository {
public:
    virtual ~IUsuarioRepository() = default;

    /**
     * @brief Registra um novo usuário no banco de dados.
     * @param usuario Ponteiro para o objeto Usuario a ser salvo.
     * @return true se o usuário foi salvo com sucesso.
     */
    virtual bool salvar(Usuario* usuario) = 0;

    /**
     * @brief Atualiza as informações de um usuário já existente.
     * @param usuario Ponteiro para o objeto com os dados atualizados.
     * @return true se a atualização foi persistida corretamente.
     */
    virtual bool atualizar(Usuario* usuario) = 0;

    /**
     * @brief Localiza um usuário através do seu identificador único.
     * @param id Identificador numérico do usuário.
     * @return Ponteiro para o Usuario encontrado ou nullptr caso não exista.
     */
    virtual Usuario* buscarPorId(int id) = 0;

    /**
     * @brief Busca um usuário pelo seu nome de login (essencial para autenticação).
     * @param login String contendo o username do usuário.
     * @return Ponteiro para o Usuario correspondente.
     */
    virtual Usuario* buscarPorLogin(const QString& login) = 0;

    /**
     * @brief Recupera a lista completa de usuários cadastrados.
     * @return QList contendo ponteiros para todos os objetos Usuario.
     */
    virtual QList<Usuario*> listarTodos() = 0;
};

#endif