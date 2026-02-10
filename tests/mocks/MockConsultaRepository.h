#pragma once
#include "../../CliniGestLogic/interfaces/repositories/IConsultaRepository.h"
#include <string>

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

    bool atualizarStatus(int id, std::string status) override {
        if (id > 0) {
            return true;
        }
        return false;
    }
};