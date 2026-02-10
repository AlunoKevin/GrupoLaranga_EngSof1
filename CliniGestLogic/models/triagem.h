#pragma once
#include <QString>

class Triagem {
private:
    QString pacienteNome;
    QString pressao;
    double temperatura;
    double peso;
    int urgencia;

public:
    Triagem() = default;
    Triagem(QString n, QString p, double t, double pe, int u) 
        : pacienteNome(n), pressao(p), temperatura(t), peso(pe), urgencia(u) {}

    QString getPacienteNome() const { return pacienteNome; }
    QString getPressao() const { return pressao; }
    double getTemperatura() const { return temperatura; }
    double getPeso() const { return peso; }
    int getUrgencia() const { return urgencia; }
    void setPacienteNome(const QString& n) { pacienteNome = n; }
    void setPressao(const QString& p) { pressao = p; }
    void setTemperatura(double t) { temperatura = t; }
    void setPeso(double p) { peso = p; }
    void setUrgencia(int u) { urgencia = u; }
};