#pragma once
#include "../../models/triagem.h"

class ITriagemRepository {
public:
    virtual ~ITriagemRepository() = default;
    virtual bool salvar(const Triagem& triagem) = 0;
};