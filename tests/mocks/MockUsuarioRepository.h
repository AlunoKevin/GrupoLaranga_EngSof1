#ifndef MOCKUSUARIOREPOSITORY_H
#define MOCKUSUARIOREPOSITORY_H

#include "../CliniGestLogic/interfaces/repositories/IUsuarioRepository.h"
#include <QMap>

class MockUsuarioRepository : public IUsuarioRepository {
public:
    QMap<int, Usuario*> usuarios;

    bool salvar(Usuario* u) override {
        usuarios[u->getId()] = u;
        return true;
    }

    bool atualizar(Usuario* u) override {
        if (usuarios.contains(u->getId())) {
            usuarios[u->getId()] = u;
            return true;
        }
        return false;
    }

    Usuario* buscarPorId(int id) override {
        return usuarios.value(id, nullptr);
    }

    Usuario* buscarPorLogin(const QString& login) override {
        for(auto u : usuarios) if(u->getLogin() == login) return u;
        return nullptr;
    }

    QList<Usuario*> listarTodos() override {
        return usuarios.values();
    }
};

#endif