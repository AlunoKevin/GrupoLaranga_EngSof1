#ifndef IATENDIMENTOREPOSITORY_H
#define IATENDIMENTOREPOSITORY_H

#include "../../models/atendimento.h"

class IAtendimentoRepository {
public:
    virtual ~IAtendimentoRepository() {}
    virtual bool salvar(const Atendimento& atendimento) = 0;
};

#endif // IATENDIMENTOREPOSITORY_H