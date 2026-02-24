#pragma once
#include <QList>
#include "../../models/consulta.h"

/**
 * @interface IServicoAgendamento
 * @brief Interface que define as regras de negócio para o agendamento de consultas.
 * @details Esta interface serve como contrato para a implementação da lógica de validação de horários e datas.
 */
class IServicoAgendamento
{
public:
    virtual ~IServicoAgendamento() = default;

    /**
     * @brief Realiza o processamento e a validação de um novo agendamento.
     * @param consulta Referência constante para o objeto Consulta com os dados (médico, paciente, data).
     * @return true se a consulta atender aos requisitos de negócio e for agendada com sucesso.
     */
    virtual bool agendar(const Consulta& consulta) = 0;
};