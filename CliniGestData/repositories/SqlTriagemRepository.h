<<<<<<< Updated upstream
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
 * * Esta classe faz parte da camada Data Access e comunica-se diretamente com o banco.
 */
class SqlTriagemRepository : public ITriagemRepository
{
private:
    QSqlDatabase m_db;

public:
    explicit SqlTriagemRepository(QSqlDatabase db) : m_db(db) {
        // Cria a tabela se ela não existir (Garante que o teste não quebre)
        QSqlQuery query(m_db);
        query.exec("CREATE TABLE IF NOT EXISTS triagem ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "pressao TEXT, "
                   "temperatura REAL, "
                   "peso REAL, "
                   "status TEXT, " 
                   "urgencia INTEGER)");
    }

    bool salvar(const Triagem& triagem) override {
        QSqlQuery query(m_db);
        query.prepare("INSERT INTO triagem (pressao, temperatura, peso, urgencia) "
                      "VALUES (:pressao, :temp, :peso, :urgencia)");
        
        // Mapeando os dados do objeto Model para as colunas do banco
        query.bindValue(":pressao", triagem.getPressao());
        query.bindValue(":temp", triagem.getTemperatura());
        query.bindValue(":peso", 0.0); // Caso precise adicionar getPeso no model
        query.bindValue(":urgencia", 0); // Placeholder para o nível de risco

        return query.exec();
    }

    bool atualizarStatus(int id, QString status) override {
        QSqlQuery query(m_db);
        query.prepare("UPDATE triagem SET status = :status WHERE id = :id");
        query.bindValue(":status", status);
        query.bindValue(":id", id);

        if (!query.exec()) {
            qDebug() << "Erro ao atualizar status da triagem:" << query.lastError().text();
            return false;
        }
        return true;
    }
};

=======
#ifndef SQLTRIAGEMREPOSITORY_H
#define SQLTRIAGEMREPOSITORY_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include "../../CliniGestLogic/interfaces/repositories/ITriagemRepository.h"
#include "../../CliniGestLogic/models/triagem.h"

/**
 * @class SqlTriagemRepository
 * @brief Implementação do repositório de triagem utilizando SQL (SQLite).
 * * Esta classe faz parte da camada Data Access e comunica-se diretamente com o banco.
 */
class SqlTriagemRepository : public ITriagemRepository
{
private:
    QSqlDatabase m_db;

public:
    explicit SqlTriagemRepository(QSqlDatabase db);
    virtual ~SqlTriagemRepository() {} 

    bool salvar(const Triagem& triagem) override;

    Triagem buscarPorPaciente(const QString& cpf);
};

>>>>>>> Stashed changes
#endif // SQLTRIAGEMREPOSITORY_H