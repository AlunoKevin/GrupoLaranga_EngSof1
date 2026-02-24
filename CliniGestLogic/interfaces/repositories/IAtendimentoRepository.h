#ifndef IATENDIMENTOREPOSITORY_H
#define IATENDIMENTOREPOSITORY_H

#include "../../models/atendimento.h"

/**
 * @interface IAtendimentoRepository
 * @brief Interface que define o contrato para armazenamento de atendimentos médicos.
 */
class IAtendimentoRepository {
public:
    virtual ~IAtendimentoRepository() {}

    /**
     * @brief Salva o registro final do atendimento realizado pelo médico.
     * @param atendimento Referência constante para os dados do atendimento.
     * @return true se o registro foi salvo.
     */
    virtual bool salvar(const Atendimento& atendimento) = 0;
};

#endif