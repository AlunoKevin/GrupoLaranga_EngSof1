#include "sistemafacade.h"

SistemaFacade::SistemaFacade()
{
}

bool SistemaFacade::login(const QString& usuario, const QString& senha)
{
    // Placeholder logic
    return usuario == "admin" && senha == "123";
}

bool SistemaFacade::agendarConsulta(int, int, const QString&)
{
    // Call ServicoAgendamento later
    return true;
}

bool SistemaFacade::cancelarConsulta(int)
{
    return true;
}
