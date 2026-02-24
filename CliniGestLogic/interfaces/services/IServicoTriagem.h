#pragma once
#include "../../models/triagem.h"

/**
 * @interface IServicoTriagem
 * @brief Interface que define o contrato para as regras de negócio da triagem.
 * @details Esta interface é responsável por validar e processar os sinais vitais coletados dos pacientes.
 */
class IServicoTriagem {
public:
    virtual ~IServicoTriagem() = default;

    /**
     * @brief Realiza o processamento e o registro de uma nova triagem no sistema.
     * @param triagem Referência constante para o objeto Triagem contendo peso, pressão, temperatura e sintomas.
     * @return true se os dados forem válidos e o registro for persistido com sucesso.
     */
    virtual bool registrarTriagem(const Triagem& triagem) = 0;
};