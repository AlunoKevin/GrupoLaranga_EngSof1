#ifndef SISTEMAFACADE_H
#define SISTEMAFACADE_H

#include "../interfaces/services/IServicoAgendamento.h"
#include "../interfaces/services/IServicoTriagem.h"
#include "../interfaces/repositories/IConsultaRepository.h"
#include "../interfaces/repositories/ITriagemRepository.h"
#include "../models/consulta.h"
#include "../models/triagem.h"
#include <QString>

class SistemaFacade
{
public:
    explicit SistemaFacade(IConsultaRepository* consultaRepo, ITriagemRepository* triagemRepo);
    ~SistemaFacade();

    bool agendarConsulta(const Consulta& consulta);
    
    bool registrarTriagem(const Triagem& triagem);

    bool autenticar(QString usuario, QString senha);

private:
    IConsultaRepository* m_consultaRepo;
    ITriagemRepository* m_triagemRepo;
    IServicoAgendamento* m_servicoAgendamento;
    IServicoTriagem* m_servicoTriagem;
};

#endif // SISTEMAFACADE_H