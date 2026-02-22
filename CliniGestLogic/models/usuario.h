#ifndef USUARIO_H
#define USUARIO_H

#include <QString>

class Usuario
{
protected:
    int id;
    QString nome;
    QString cpf;      
    QString email;    
    QString login;    // Necessário para o Hugo (Autenticação)
    QString senha;    // Necessário para o Hugo (Criptografia)
    QString perfil;   // Necessário para a Thais (Controle de Acesso)

public:
    Usuario() : id(0) {}
    Usuario(int id, const QString& nome, const QString& cpf, const QString& email, 
            const QString& login, const QString& senha, const QString& perfil)
        : id(id), nome(nome), cpf(cpf), email(email), login(login), senha(senha), perfil(perfil) {}

    virtual ~Usuario() = default;

    int getId() const { return id; }
    QString getNome() const { return nome; }
    QString getCpf() const { return cpf; }
    QString getEmail() const { return email; }
    QString getLogin() const { return login; }
    QString getSenha() const { return senha; }
    QString getPerfil() const { return perfil; }

    void setNome(const QString& n) { nome = n; }
    void setEmail(const QString& e) { email = e; }
    void setSenha(const QString& s) { senha = s; }
};

#endif