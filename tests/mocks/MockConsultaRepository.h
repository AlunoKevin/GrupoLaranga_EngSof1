#pragma once
#include "../../CliniGestLogic/interfaces/repositories/IConsultaRepository.h"

class MockConsultaRepository : public IConsultaRepository
{
public:
    QList<Consulta> data;

    bool salvar(const Consulta& c) override {
        data.append(c);
        return true;
    }

    QList<Consulta> listarPorData(const QDate&) override {
        return data;
    }
};
