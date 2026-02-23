#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include <QString>

/**
 * @class Atendimento
 * @brief Classe de modelo que representa o registro de um atendimento médico realizado.
 * @details Armazena as conclusões do médico, incluindo diagnóstico, prescrições e observações, 
 * vinculando-as a uma triagem específica.
 */
class Atendimento {
public:
    /**
     * @brief Construtor da classe Atendimento.
     * @param idTriagem Identificador da triagem que originou este atendimento (default 0).
     * @param diagnostico Descrição do diagnóstico médico.
     * @param prescricao Medicamentos ou tratamentos receitados.
     * @param exames Lista de exames solicitados.
     * @param observacoes Notas adicionais sobre o atendimento.
     */
    Atendimento(int idTriagem = 0, QString diagnostico = "", QString prescricao = "", 
                QString exames = "", QString observacoes = "")
        : m_id(0), m_idTriagem(idTriagem), m_diagnostico(diagnostico), 
          m_prescricao(prescricao), m_exames(exames), m_observacoes(observacoes) {}

    /** @return O identificador único do atendimento. */
    int id() const { return m_id; }
    /** @param id Define o identificador único do atendimento. */
    void setId(int id) { m_id = id; }

    /** @return O ID da triagem associada. */
    int idTriagem() const { return m_idTriagem; } 
    /** @param id Define o ID da triagem vinculada. */
    void setIdTriagem(int id) { m_idTriagem = id; }

    /** @return O diagnóstico médico registrado. */
    QString diagnostico() const { return m_diagnostico; }
    /** @param d Define o diagnóstico médico. */
    void setDiagnostico(const QString &d) { m_diagnostico = d; }

    /** @return A prescrição médica. */
    QString prescricao() const { return m_prescricao; }
    /** @param p Define a prescrição médica. */
    void setPrescricao(const QString &p) { m_prescricao = p; }

    /** @return Os exames solicitados. */
    QString exames() const { return m_exames; }
    /** @param e Define os exames solicitados. */
    void setExames(const QString &e) { m_exames = e; }

    /** @return Observações gerais do atendimento. */
    QString observacoes() const { return m_observacoes; }
    /** @param obs Define as observações gerais. */
    void setObservacoes(const QString &obs) { m_observacoes = obs; }

private:
    int m_id;               /**< ID autoincremento no banco de dados. */
    int m_idTriagem;        /**< Chave estrangeira para a tabela de triagem. */
    QString m_diagnostico;  /**< Texto do diagnóstico. */
    QString m_prescricao;   /**< Texto da prescrição. */
    QString m_exames;       /**< Texto dos exames. */
    QString m_observacoes;  /**< Texto de observações livres. */
};

#endif // ATENDIMENTO_H