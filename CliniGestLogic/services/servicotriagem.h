#pragma once
#include "../interfaces/services/IServicoTriagem.h"
#include "../interfaces/repositories/ITriagemRepository.h"

class ServicoTriagem : public IServicoTriagem {
public:
    explicit ServicoTriagem(ITriagemRepository* repo);
    bool registrarTriagem(const Triagem& triagem) override;

private:
    ITriagemRepository* m_repo;
};