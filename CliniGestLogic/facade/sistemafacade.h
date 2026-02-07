#ifndef SISTEMAFACADE_H
#define SISTEMAFACADE_H

#include <QString>

class SistemaFacade
{
public:
    SistemaFacade();

    bool login(const QString& usuario, const QString& senha);

    bool agendarConsulta(int pacienteId, int medicoId, const QString& dataHora);
    bool cancelarConsulta(int consultaId);
};

#endif
