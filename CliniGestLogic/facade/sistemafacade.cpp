#include "sistemafacade.h"
#include "interfaces/repositories/IConsultaRepository.h"


SistemaFacade::SistemaFacade(IConsultaRepository* consultaRepo)
    : m_consultaRepo(consultaRepo)
{
}
