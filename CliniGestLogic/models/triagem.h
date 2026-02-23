#pragma once
#include <QString>

/**
 * @class Triagem
 * @brief Classe de modelo que representa a triagem inicial de um paciente.
 * @details Armazena os sinais vitais coletados e o nível de urgência, servindo 
 * como base para o posterior atendimento médico.
 */
class Triagem {
private:
    QString pacienteNome; /**< Nome do paciente triado. */
    QString pressao;      /**< Pressão arterial (ex: "12/8"). */
    double temperatura;   /**< Temperatura corporal em graus Celsius. */
    double peso;          /**< Peso do paciente em quilogramas. */
    int urgencia;         /**< Nível de urgência (escala numérica). */

public:
    /**
     * @brief Construtor padrão da classe Triagem.
     */
    Triagem() = default;

    /**
     * @brief Construtor completo para inicialização de todos os sinais vitais.
     * @param n Nome do paciente.
     * @param p Pressão arterial.
     * @param t Temperatura corporal.
     * @param pe Peso.
     * @param u Nível de urgência.
     */
    Triagem(QString n, QString p, double t, double pe, int u) 
        : pacienteNome(n), pressao(p), temperatura(t), peso(pe), urgencia(u) {}

    /** @return O nome do paciente associado à triagem. */
    QString getPacienteNome() const { return pacienteNome; }
    /** @return A pressão arterial registrada. */
    QString getPressao() const { return pressao; }
    /** @return A temperatura corporal registrada. */
    double getTemperatura() const { return temperatura; }
    /** @return O peso registrado. */
    double getPeso() const { return peso; }
    /** @return O nível de urgência atribuído. */
    int getUrgencia() const { return urgencia; }

    /** @param n Define o nome do paciente. */
    void setPacienteNome(const QString& n) { pacienteNome = n; }
    /** @param p Define a pressão arterial. */
    void setPressao(const QString& p) { pressao = p; }
    /** @param t Define a temperatura corporal. */
    void setTemperatura(double t) { temperatura = t; }
    /** @param p Define o peso do paciente. */
    void setPeso(double p) { peso = p; }
    /** @param u Define o nível de urgência. */
    void setUrgencia(int u) { urgencia = u; }
};