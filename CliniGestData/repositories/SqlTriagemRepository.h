#ifndef SQLTRIAGEMREPOSITORY_H
#define SQLTRIAGEMREPOSITORY_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include "../../CliniGestLogic/interfaces/repositories/ITriagemRepository.h"
#include "../../CliniGestLogic/models/triagem.h"

/**
 * @class SqlTriagemRepository
 * @brief Implementação do repositório de triagem utilizando SQL (SQLite).
 */
class SqlTriagemRepository : public ITriagemRepository
{
private:
    QSqlDatabase m_db;

public:
    explicit SqlTriagemRepository(QSqlDatabase db);
    virtual ~SqlTriagemRepository() = default;

    // Métodos da Interface
    bool salvar(const Triagem& triagem) override;
    bool atualizarStatus(int id, QString status) override;
};

#endif // SQLTRIAGEMREPOSITORY_H