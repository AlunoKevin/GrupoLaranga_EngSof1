#ifndef USUARIO_H
#define USUARIO_H

#include <QString>

/**
 * @class Usuario
 * @brief Classe base que representa um colaborador do sistema CliniGest.
 * @details Esta classe armazena os dados comuns a todos os usuários, como informações 
 * pessoais e credenciais de acesso, servindo de base para perfis específicos (ex: Medico).
 */
class Usuario
{
protected:
    int id;           /**< Identificador único do usuário. */
    QString nome;    /**< Nome completo do colaborador. */
    QString cpf;     /**< Cadastro de Pessoa Física. */
    QString email;   /**< Endereço de e-mail institucional. */
    QString login;   /**< Nome de utilizador para autenticação . */
    QString senha;   /**< Hash da senha para segurança . */
    QString perfil;  /**< Tipo de acesso: Médico, Enfermeiro, etc.. */

public:
    /**
     * @brief Construtor padrão da classe Usuario.
     */
    Usuario() : id(0) {}

    /**
     * @brief Construtor completo para inicialização de um novo usuário.
     * @param id ID do usuário.
     * @param nome Nome completo.
     * @param cpf CPF.
     * @param email E-mail.
     * @param login Username.
     * @param senha Senha.
     * @param perfil Perfil de acesso.
     */
    Usuario(int id, const QString& nome, const QString& cpf, const QString& email, 
            const QString& login, const QString& senha, const QString& perfil)
        : id(id), nome(nome), cpf(cpf), email(email), login(login), senha(senha), perfil(perfil) {}

    /**
     * @brief Destrutor virtual para garantir a limpeza correta em classes derivadas.
     */
    virtual ~Usuario() = default;

    /** @return O ID do usuário. */
    int getId() const { return id; }
    /** @return O nome completo. */
    QString getNome() const { return nome; }
    /** @return O CPF. */
    QString getCpf() const { return cpf; }
    /** @return O e-mail. */
    QString getEmail() const { return email; }
    /** @return O login de acesso. */
    QString getLogin() const { return login; }
    /** @return A senha (hash). */
    QString getSenha() const { return senha; }
    /** @return O perfil de acesso. */
    QString getPerfil() const { return perfil; }

    /** @param n Define o novo nome. */
    void setNome(const QString& n) { nome = n; }
    /** @param e Define o novo e-mail. */
    void setEmail(const QString& e) { email = e; }
    /** @param s Define a nova senha. */
    void setSenha(const QString& s) { senha = s; }
};

#endif