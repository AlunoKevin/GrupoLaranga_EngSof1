#pragma once
#include <QList>
#include "../../models/consulta.h"

class IServicoAgendamento
{
public:
    virtual ~IServicoAgendamento() = default;

    virtual bool agendar(const Consulta& consulta) = 0;
};
