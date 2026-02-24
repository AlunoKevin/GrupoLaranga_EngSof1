#pragma once
#include "../../models/usuario.h"
#include <QList>

/**
 * @interface IServicoUsuario
 * @brief Interface que define as regras de negócio para gestão de usuários e sessões.
 * @details Esta interface centraliza as operações de busca, alteração de dados pessoais e controle do utilizador logado no sistema.
 */
class IServicoUsuario {
public:
    virtual ~IServicoUsuario() = default;
    
    /**
     * @brief Atualiza as informações básicas de cadastro de um usuário.
     * @param id Identificador único do usuário.
     * @param nome Novo nome completo.
     * @param email Novo endereço de e-mail.
     * @return true se os dados forem válidos e a atualização for confirmada.
     */
    virtual bool atualizarDadosPessoais(int id, const QString& nome, const QString& email) = 0;

    /**
     * @brief Realiza a troca da senha de acesso do usuário.
     * @param id Identificador único do usuário.
     * @param novaSenha Nova string de senha (deve ser tratada/hasheada na implementação).
     * @return true se a senha atender aos requisitos e for alterada.
     */
    virtual bool alterarSenha(int id, const QString& novaSenha) = 0;

    /**
     * @brief Recupera um usuário através do seu ID numérico.
     * @param id Identificador único.
     * @return Ponteiro para o objeto Usuario ou nullptr se não encontrado.
     */
    virtual Usuario* buscarPorId(int id) = 0;

    /**
     * @brief Localiza um usuário pelo nome de login.
     * @note Este método é essencial para o fluxo de autenticação do Hugo.
     * @param login String com o nome de utilizador.
     * @return Ponteiro para o Usuario correspondente.
     */
    virtual Usuario* buscarPorLogin(const QString& login) = 0;

    /**
     * @brief Retorna o usuário que está atualmente autenticado na sessão.
     * @return Ponteiro para o objeto Usuario da sessão ativa.
     */
    virtual Usuario* buscarUtilizadorLogado() = 0;

    /**
     * @brief Define qual usuário deve ser considerado como logado no sistema.
     * @param u Ponteiro para o objeto Usuario autenticado.
     */
    virtual void setUsuarioLogado(Usuario* u) = 0;
};