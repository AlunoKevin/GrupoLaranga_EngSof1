#pragma once
#include <QList>
#include "../../models/consulta.h"

class IConsultaRepository
{
public:
    virtual ~IConsultaRepository() = default;

    virtual bool salvar(const Consulta& consulta) = 0;
    virtual QList<Consulta> listarPorData(const QDate& data) = 0;
};
