#ifndef SQLATENDIMENTOREPOSITORY_H
#define SQLATENDIMENTOREPOSITORY_H

#include "../../CliniGestLogic/interfaces/repositories/IAtendimentoRepository.h"
#include "../../CliniGestLogic/models/atendimento.h"
#include <QSqlDatabase>
#include <QSqlQuery>

class SqlAtendimentoRepository : public IAtendimentoRepository {
public:
    explicit SqlAtendimentoRepository(QSqlDatabase db) : m_db(db) {
        QSqlQuery query(m_db);
        query.exec("CREATE TABLE IF NOT EXISTS atendimento ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "id_triagem INTEGER, "
                   "diagnostico TEXT, "
                   "prescricao TEXT, "
                   "exames TEXT, "
                   "observacoes TEXT)");
    }

    bool salvar(const Atendimento& a) override {
        QSqlQuery query(m_db);
        query.prepare("INSERT INTO atendimento (id_triagem, diagnostico, prescricao, exames, observacoes) "
                      "VALUES (:triagem, :diag, :presc, :exames, :obs)");
        query.bindValue(":triagem", a.idTriagem());
        query.bindValue(":diag", a.diagnostico());
        query.bindValue(":presc", a.prescricao());
        query.bindValue(":exames", a.exames());
        query.bindValue(":obs", a.observacoes());
        return query.exec();
    }

private:
    QSqlDatabase m_db;
};

#endif // SQLATENDIMENTOREPOSITORY_H