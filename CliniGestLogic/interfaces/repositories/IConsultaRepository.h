#pragma once
#include <QList>
#include "../../models/consulta.h"

/**
 * @interface IConsultaRepository
 * @brief Interface responsável pelas operações de banco de dados relacionadas a consultas.
 */
class IConsultaRepository
{
public:
    virtual ~IConsultaRepository() = default;

    /**
     * @brief Persiste uma nova consulta médica.
     * @param consulta Dados da consulta a ser agendada.
     * @return true se salva corretamente.
     */
    virtual bool salvar(const Consulta& consulta) = 0;

    /**
     * @brief Lista todas as consultas agendadas para um dia específico.
     * @param data A data de filtro.
     * @return Lista de consultas encontradas.
     */
    virtual QList<Consulta> listarPorData(const QDate& data) = 0;

    /**
     * @brief Atualiza a situação de uma consulta (ex: Finalizada, Cancelada).
     * @param id Identificador da consulta.
     * @param status Novo status em formato std::string.
     * @return true se a atualização foi bem-sucedida.
     */
    virtual bool atualizarStatus(int id, std::string status) = 0;
};