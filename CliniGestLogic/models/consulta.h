#pragma once
#include <QDate>
#include <QTime>

class Consulta
{
private:
    int id;
    QDate data;
    QTime horario;

public:
    Consulta() = default;

    Consulta(QDate d, QTime h)
        : data(d), horario(h) {}

    QDate getData() const { return data; }
    QTime getHorario() const { return horario; }

    void setData(const QDate& d) { data = d; }
    void setHorario(const QTime& h) { horario = h; }
};
