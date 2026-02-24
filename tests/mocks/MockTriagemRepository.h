#pragma once
#include <QList>
#include "../../CliniGestLogic/interfaces/repositories/ITriagemRepository.h"
#include "../../CliniGestLogic/models/triagem.h"

class MockTriagemRepository : public ITriagemRepository
{
public:
    QList<Triagem> triagensSalvas;

    bool salvar(const Triagem& t) override {
        triagensSalvas.append(t);
        return true; 
    }

    bool atualizarStatus(int id, QString status) override {
        Q_UNUSED(id);
        Q_UNUSED(status);
        return true; 
    }
};