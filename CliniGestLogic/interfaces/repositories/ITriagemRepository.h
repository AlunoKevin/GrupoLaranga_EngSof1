#ifndef ITRIAGEMREPOSITORY_H
#define ITRIAGEMREPOSITORY_H

#include "../../models/triagem.h"
#include <QString> 

/**
 * @interface ITriagemRepository
 * @brief Interface para gerenciar a persistência dos dados de triagem.
 */
class ITriagemRepository {
public:
    virtual ~ITriagemRepository() {}

    /**
     * @brief Salva os dados de sinais vitais coletados na triagem.
     * @param triagem Referência constante para os dados de triagem.
     * @return true se os dados foram inseridos com sucesso no SQL.
     */
    virtual bool salvar(const Triagem& triagem) = 0;
    
    /**
     * @brief Modifica o status de uma triagem específica (ex: Aguardando Atendimento).
     * @param id ID da triagem no sistema.
     * @param status Nova descrição do status.
     * @return true se o status foi alterado.
     */
    virtual bool atualizarStatus(int id, QString status) = 0; 
};

#endif