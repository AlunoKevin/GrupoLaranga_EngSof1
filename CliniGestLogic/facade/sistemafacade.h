#ifndef SISTEMAFACADE_H
#define SISTEMAFACADE_H

#include <QString>
#include "../interfaces/repositories/IConsultaRepository.h"
#include "../interfaces/repositories/ITriagemRepository.h"
#include "../interfaces/repositories/IAtendimentoRepository.h" 
#include "../models/consulta.h"
#include "../models/triagem.h"
#include "../models/atendimento.h" 

class SistemaFacade
{
public:
    SistemaFacade(IConsultaRepository* consultaRepo, 
                  ITriagemRepository* triagemRepo,
                  IAtendimentoRepository* atendimentoRepo);
    
    ~SistemaFacade();

    bool agendarConsulta(const Consulta& consulta);

    bool registrarTriagem(const Triagem& triagem);

    bool registrarAtendimento(const Atendimento& atendimento);

    bool autenticar(const QString& usuario, const QString& senha);

private:
    IConsultaRepository* m_consultaRepo;
    ITriagemRepository* m_triagemRepo;
    IAtendimentoRepository* m_atendimentoRepo; 
};

#endif // SISTEMAFACADE_H