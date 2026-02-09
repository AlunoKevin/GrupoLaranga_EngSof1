#pragma once
#include "../interfaces/services/IServicoAgendamento.h"
#include "../interfaces/repositories/IConsultaRepository.h"

class ServicoAgendamento : public IServicoAgendamento
{
public:
    explicit ServicoAgendamento(IConsultaRepository* repo);

    bool agendar(const Consulta& consulta) override;
   
    bool cancelar(int id);
private:
    IConsultaRepository* m_repo;
};
