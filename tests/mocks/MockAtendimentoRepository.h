#pragma once
#include "../../CliniGestLogic/interfaces/repositories/IAtendimentoRepository.h"
#include <QList>

class MockAtendimentoRepository : public IAtendimentoRepository
{
public:
    QList<Atendimento> data;

    bool salvar(const Atendimento& a) override {
        data.append(a);
        return true;
    }
};