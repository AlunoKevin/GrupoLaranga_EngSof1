#ifndef SISTEMAFACADE_H
#define SISTEMAFACADE_H

// Interfaces de Serviços
#include "../interfaces/services/IServicoAgendamento.h"
#include "../interfaces/services/IServicoTriagem.h"
#include "../interfaces/services/IServicoAtendimento.h"

// Interfaces de Repositórios
#include "../interfaces/repositories/IConsultaRepository.h"
#include "../interfaces/repositories/ITriagemRepository.h"
#include "../interfaces/repositories/IAtendimentoRepository.h"

// Modelos
#include "../models/consulta.h"
#include "../models/triagem.h"
#include "../models/atendimento.h"

class SistemaFacade
{
public:
    explicit SistemaFacade(IConsultaRepository* consultaRepo, 
                           ITriagemRepository* triagemRepo,
                           IAtendimentoRepository* atendimentoRepo);
    ~SistemaFacade();

    bool agendarConsulta(const Consulta& consulta);
    bool registrarTriagem(const Triagem& triagem);

    bool autenticar(const QString& usuario, const QString& senha);
    bool registrarAtendimento(const Atendimento& atendimento); 

private:
    IConsultaRepository* m_consultaRepo;
    ITriagemRepository* m_triagemRepo;
    IAtendimentoRepository* m_atendimentoRepo;

    IServicoAgendamento* m_servicoAgendamento;
    IServicoTriagem* m_servicoTriagem;
    IServicoAtendimento* m_servicoAtendimento;
};

#endif // SISTEMAFACADE_H