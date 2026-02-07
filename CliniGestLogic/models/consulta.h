#ifndef CONSULTA_H
#define CONSULTA_H

#include <QDateTime>

class Paciente;
class Medico;

class Consulta
{
public:
    enum Status { AGENDADA, CANCELADA, FINALIZADA };

    Consulta(Paciente* paciente, Medico* medico, QDateTime dataHora);

    void setStatus(Status s);

private:
    Paciente* paciente;
    Medico* medico;
    QDateTime dataHora;
    Status status;
};

#endif
