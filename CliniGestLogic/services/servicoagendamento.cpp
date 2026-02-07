#include "servicoagendamento.h"

ServicoAgendamento::ServicoAgendamento(IConsultaRepository* r)
    : repo(r) {}

bool ServicoAgendamento::agendar(const Consulta& consulta)
{
    auto existentes = repo->listarPorData(consulta.getData());

    for (const auto& c : existentes) {
        if (c.getHorario() == consulta.getHorario())
            return false; // horário ocupado
    }

    return repo->salvar(consulta);
}
