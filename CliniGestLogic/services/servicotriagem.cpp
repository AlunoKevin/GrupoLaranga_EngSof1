#include "servicotriagem.h"

ServicoTriagem::ServicoTriagem(ITriagemRepository* repo)
    : m_repo(repo) {}

bool ServicoTriagem::registrarTriagem(const Triagem& triagem) {
    // Temperatura não pode ser absurda
    if(triagem.getTemperatura() < 30 || triagem.getTemperatura() > 45) {
        return false;
    }
    return m_repo->salvar(triagem);
}