#ifndef PACIENTE_H
#define PACIENTE_H

#include <QString>

/**
 * @class Paciente
 * @brief Classe de modelo que representa um paciente no sistema CliniGest.
 * @details Esta classe armazena os dados básicos de identificação do paciente,
 * sendo utilizada como referência fundamental para agendamentos e atendimentos.
 */
class Paciente
{
public:
    /**
     * @brief Construtor da classe Paciente.
     * @param id Identificador único do paciente no banco de dados.
     * @param nome Nome completo do paciente.
     */
    Paciente(int id, const QString& nome);

private:
    int id;       /**< Identificador numérico único do paciente. */
    QString nome; /**< Nome completo do paciente. */
};

#endif