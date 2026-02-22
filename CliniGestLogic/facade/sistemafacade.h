#ifndef SISTEMAFACADE_H
#define SISTEMAFACADE_H

#include <QString>
#include "../interfaces/repositories/IConsultaRepository.h"
#include "../interfaces/repositories/ITriagemRepository.h"
#include "../interfaces/repositories/IAtendimentoRepository.h" 
#include "../interfaces/repositories/IUsuarioRepository.h" 
#include "../interfaces/services/IServicoUsuario.h"
#include "../models/consulta.h"
#include "../models/triagem.h"
#include "../models/atendimento.h"
#include "../models/usuario.h"

class SistemaFacade
{
public:
    SistemaFacade(IConsultaRepository* consultaRepo, 
                  ITriagemRepository* triagemRepo,
                  IAtendimentoRepository* atendimentoRepo,
                  IUsuarioRepository* usuarioRepo,
                  IServicoUsuario* usuarioServico);
    
    ~SistemaFacade();

    bool agendarConsulta(const Consulta& consulta);

    bool registrarTriagem(const Triagem& triagem);

    bool registrarAtendimento(const Atendimento& atendimento);

    bool autenticar(const QString& usuario, const QString& senha);

    bool atualizarDadosUtilizador(int id, const QString& nome, const QString& email);
    bool alterarSenha(int id, const QString& novaSenha);
    Usuario* buscarUtilizadorLogado();

private:
    IConsultaRepository* m_consultaRepo;
    ITriagemRepository* m_triagemRepo;
    IAtendimentoRepository* m_atendimentoRepo;
    IUsuarioRepository* m_usuarioRepo;
    IServicoUsuario* m_usuarioServico; 
};

#endif // SISTEMAFACADE_H