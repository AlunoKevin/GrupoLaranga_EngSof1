#pragma once
#include <QString>

class Triagem {
private:
    QString pressao;
    double temperatura;
    double peso;
    int urgencia;

public:
    Triagem() = default;
    Triagem(QString p, double t, double pe, int u) 
        : pressao(p), temperatura(t), peso(pe), urgencia(u) {}

    QString getPressao() const { return pressao; }
    double getTemperatura() const { return temperatura; }
    void setPressao(const QString& p) { pressao = p; }
};