#pragma once
#include "../../models/triagem.h"

class IServicoTriagem {
public:
    virtual ~IServicoTriagem() = default;
    virtual bool registrarTriagem(const Triagem& triagem) = 0;
};