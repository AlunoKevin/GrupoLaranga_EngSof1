#ifndef ISERVICOATENDIMENTO_H
#define ISERVICOATENDIMENTO_H

#include "../../models/atendimento.h"

class IServicoAtendimento {
public:
    virtual ~IServicoAtendimento() {}
    virtual bool registrar(const Atendimento& atendimento) = 0;
};

#endif // ISERVICOATENDIMENTO_H