#ifndef MEDICO_H
#define MEDICO_H

#include "usuario.h"

/**
 * @class Medico
 * @brief Classe que representa a entidade Médico no sistema.
 * @details Esta classe herda da classe base Usuario e implementa a identificação 
 * específica do perfil para os profissionais de medicina dentro do CliniGest.
 */
class Medico : public Usuario
{
public:
    /**
     * @brief Construtor da classe Medico.
     * @param id Identificador único do médico (herdado de Usuario).
     * @param nome Nome completo do profissional.
     */
    Medico(int id, const QString& nome);

    /**
     * @brief Retorna a identificação do tipo de usuário.
     * @return Uma QString contendo a string "Médico" para controle de acesso e exibição.
     */
    QString getTipo() const override;
};

#endif