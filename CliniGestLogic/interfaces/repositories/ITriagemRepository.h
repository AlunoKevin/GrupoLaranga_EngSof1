#ifndef ITRIAGEMREPOSITORY_H
#define ITRIAGEMREPOSITORY_H

#include "../../models/triagem.h"
#include <QString> 

class ITriagemRepository {
public:
    virtual ~ITriagemRepository() {}

    virtual bool salvar(const Triagem& triagem) = 0;
    
    virtual bool atualizarStatus(int id, QString status) = 0; 
};

#endif // ITRIAGEMREPOSITORY_H