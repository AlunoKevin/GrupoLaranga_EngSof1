#include "SqlConsultaRepository.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

SqlConsultaRepository::SqlConsultaRepository(QSqlDatabase database)
    : db(database)
{
}

bool SqlConsultaRepository::salvar(const Consulta& consulta)
{
    // Para a Sprint 1, se ainda não for o foco, pode manter o return true,
    // mas o ideal é já deixar o esqueleto da query pronto.
    return true;
}

QList<Consulta> SqlConsultaRepository::listarPorData(const QDate& data)
{
    return {};
}

// Implementação da sua parte de cancelamento
bool SqlConsultaRepository::atualizarStatus(int id, std::string novoStatus) {
    // Usamos o objeto 'db' para garantir que a query rode na conexão certa
    QSqlQuery query(db); 
    
    query.prepare("UPDATE consultas SET status = :status WHERE id = :id");
    
    // Convertendo std::string para QString (que o QSqlQuery exige)
    query.bindValue(":status", QString::fromStdString(novoStatus));
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erro ao atualizar status no SQL:" << query.lastError().text();
        return false;
    }
    
    return true; 
}