#ifndef SISTEMAFACADE_H
#define SISTEMAFACADE_H

#include "interfaces/services/IServicoAgendamento.h"
#include "interfaces/repositories/IConsultaRepository.h"


class IConsultaRepository;

class SistemaFacade
{
public:
    explicit SistemaFacade(IConsultaRepository* consultaRepo);

private:
    IConsultaRepository* m_consultaRepo;
};

#endif // SISTEMAFACADE_H
