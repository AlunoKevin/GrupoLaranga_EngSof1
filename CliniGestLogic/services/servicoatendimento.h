#ifndef SERVICOATENDIMENTO_H
#define SERVICOATENDIMENTO_H

#include "../interfaces/services/IServicoAtendimento.h"
#include "../interfaces/repositories/IAtendimentoRepository.h"

class ServicoAtendimento : public IServicoAtendimento {
private:
    IAtendimentoRepository* m_repo;

public:
    explicit ServicoAtendimento(IAtendimentoRepository* repo);

    bool registrar(const Atendimento& atendimento) override;
};

#endif // SERVICOATENDIMENTO_H