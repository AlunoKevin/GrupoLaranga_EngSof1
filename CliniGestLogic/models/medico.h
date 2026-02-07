#ifndef MEDICO_H
#define MEDICO_H

#include "usuario.h"

class Medico : public Usuario
{
public:
    Medico(int id, const QString& nome);

    QString getTipo() const override;
};

#endif
