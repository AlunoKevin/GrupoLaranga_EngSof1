#ifndef USUARIO_H
#define USUARIO_H

#include <QString>

class Usuario
{
public:
    Usuario(int id, const QString& nome);
    virtual ~Usuario() = default;

    virtual QString getTipo() const = 0;

protected:
    int id;
    QString nome;
};

#endif
