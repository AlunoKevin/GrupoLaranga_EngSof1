#ifndef CONSULTA_H
#define CONSULTA_H

#include <string>
#include <QDate>
#include <QTime>

/**
 * @class Consulta
 * @brief Classe de modelo que representa um agendamento de consulta médica.
 * @details Armazena informações sobre o vínculo entre paciente e médico, 
 * além da data e horário previstos para o encontro.
 */
class Consulta {
public:
    /**
     * @brief Construtor padrão da classe Consulta.
     */
    Consulta() = default;

    /**
     * @brief Construtor completo para inicialização de todos os atributos.
     * @param id Identificador único da consulta no banco de dados.
     * @param p Nome do paciente.
     * @param m Nome do médico responsável.
     * @param d Data agendada.
     * @param h Horário agendado.
     */
    Consulta(int id, std::string p, std::string m, QDate d, QTime h)
        : id(id), paciente(p), medico(m), data(d), horario(h) {}

    // Atributos públicos (seguindo a estrutura original do projeto)
    int id;                 /**< Identificador único da consulta. */
    std::string paciente;   /**< Nome do paciente. */
    std::string medico;     /**< Nome do médico. */
    QDate data;             /**< Data da consulta. */
    QTime horario;          /**< Horário da consulta. */

    /** @param p Define o nome do paciente. */
    void setPaciente(const std::string& p) { paciente = p; }
    /** @param m Define o nome do médico. */
    void setMedico(const std::string& m) { medico = m; }
    /** @param d Define a data da consulta. */
    void setData(const QDate& d) { data = d; }
    /** @param h Define o horário da consulta. */
    void setHorario(const QTime& h) { horario = h; } 
    /** @param i Define o identificador único da consulta. */
    void setId(int i) { id = i; }

    /** @return Nome do paciente. */
    std::string getPaciente() const { return paciente; }
    /** @return Nome do médico. */
    std::string getMedico() const { return medico; }
    /** @return Data da consulta. */
    QDate getData() const { return data; }
    /** @return Horário da consulta. */
    QTime getHorario() const { return horario; }
    /** @return ID da consulta. */
    int getId() const { return id; }
};

#endif // CONSULTA_H