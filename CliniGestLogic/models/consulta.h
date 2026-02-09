#ifndef CONSULTA_H
#define CONSULTA_H

#include <string>
#include <QDate>
#include <QTime>

class Consulta {
public:
    Consulta() = default;

    // Construtor completo
    Consulta(int id, std::string p, std::string m, QDate d, QTime h)
        : id(id), paciente(p), medico(m), data(d), horario(h) {}

    // Atributos
    int id;
    std::string paciente;
    std::string medico;
    QDate data;
    QTime horario;

    // Setters (Essenciais para o seu erro sumir)
    void setPaciente(const std::string& p) { paciente = p; }
    void setMedico(const std::string& m) { medico = m; }
    void setData(const QDate& d) { data = d; }
    void setHorario(const QTime& h) { horario = h; } // Note: é setHorario, não setHora
    void setId(int i) { id = i; }

    // Getters
    std::string getPaciente() const { return paciente; }
    std::string getMedico() const { return medico; }
    QDate getData() const { return data; }
    QTime getHorario() const { return horario; }
    int getId() const { return id; }
};

#endif // CONSULTA_H
