#ifndef SISTEMAFACADE_H
#define SISTEMAFACADE_H

#include "../interfaces/services/IServicoAgendamento.h"
#include "../interfaces/repositories/IConsultaRepository.h"
#include "../models/consulta.h"

class SistemaFacade
{
public:
    explicit SistemaFacade(IConsultaRepository* consultaRepo);
    ~SistemaFacade();

    bool agendarConsulta(const Consulta& consulta);

private:
    IConsultaRepository* m_consultaRepo;
    IServicoAgendamento* m_servicoAgendamento;
};

#endif // SISTEMAFACADE_H
