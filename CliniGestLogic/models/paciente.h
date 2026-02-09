#ifndef PACIENTE_H
#define PACIENTE_H

#include <QString>

class Paciente
{
public:
    Paciente(int id, const QString& nome);

private:
    int id;
    QString nome;
};

#endif
