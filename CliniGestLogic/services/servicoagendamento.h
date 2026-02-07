#pragma once
#include "../interfaces/services/IServicoAgendamento.h"
#include "../interfaces/repositories/IConsultaRepository.h"

class ServicoAgendamento : public IServicoAgendamento
{
private:
    IConsultaRepository* repo;

public:
    explicit ServicoAgendamento(IConsultaRepository* r);

    bool agendar(const Consulta& consulta) override;
};
