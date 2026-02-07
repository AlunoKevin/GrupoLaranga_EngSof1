#ifndef SERVICOAGENDAMENTO_H
#define SERVICOAGENDAMENTO_H

class ServicoAgendamento
{
public:
    bool agendar(int pacienteId, int medicoId);
    bool cancelar(int consultaId);
};

#endif
