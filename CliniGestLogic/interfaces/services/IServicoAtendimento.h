#ifndef ISERVICOATENDIMENTO_H
#define ISERVICOATENDIMENTO_H

#include "../../models/atendimento.h"

/**
 * @interface IServicoAtendimento
 * @brief Interface que define o contrato para os serviços de atendimento médico.
 * @details Esta interface é responsável por mediar o registro final das informações coletadas pelo médico durante a consulta.
 */
class IServicoAtendimento {
public:
    virtual ~IServicoAtendimento() {}

    /**
     * @brief Registra um novo atendimento médico no sistema.
     * @param atendimento Referência constante para o objeto Atendimento contendo diagnóstico e prescrições.
     * @return true se o atendimento for validado pelas regras de negócio e salvo com sucesso.
     */
    virtual bool registrar(const Atendimento& atendimento) = 0;
};

#endif // ISERVICOATENDIMENTO_H