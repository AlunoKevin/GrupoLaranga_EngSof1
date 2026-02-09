#pragma once
#include <QList>
#include "../../CliniGestLogic/interfaces/repositories/ITriagemRepository.h"
#include "../../CliniGestLogic/models/triagem.h"

class MockTriagemRepository : public ITriagemRepository
{
public:
    // Lista em memória para simular o banco de dados
    QList<Triagem> triagensSalvas;

    bool salvar(const Triagem& t) override {
        triagensSalvas.append(t);
        return true; // Simula sucesso no salvamento
    }
};