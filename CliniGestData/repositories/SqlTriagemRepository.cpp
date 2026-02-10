#include "SqlTriagemRepository.h"

SqlTriagemRepository::SqlTriagemRepository(QSqlDatabase db) : m_db(db) 
{
    QSqlQuery query(m_db);
    // Criando a tabela com a coluna status e paciente_nome para manter compatibilidade
    query.exec("CREATE TABLE IF NOT EXISTS triagem ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "paciente_nome TEXT, "
               "pressao TEXT, "
               "temperatura REAL, "
               "peso REAL, "
               "status TEXT, " 
               "urgencia INTEGER)");
}

bool SqlTriagemRepository::salvar(const Triagem& triagem) {
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO triagem (paciente_nome, pressao, temperatura, peso, urgencia, status) "
                  "VALUES (:nome, :pressao, :temp, :peso, :urgencia, :status)");

    query.bindValue(":nome", triagem.getPacienteNome()); 
    query.bindValue(":pressao", triagem.getPressao());
    query.bindValue(":temp", triagem.getTemperatura());
    query.bindValue(":peso", triagem.getPeso());
    query.bindValue(":urgencia", triagem.getUrgencia());
    query.bindValue(":status", "Pendente"); // Status inicial padrão

    if (!query.exec()) {
        qDebug() << "ERRO NO SQLITE (salvar):" << query.lastError().text();
        return false;
    }
    return true;
}

bool SqlTriagemRepository::atualizarStatus(int id, QString status) {
    QSqlQuery query(m_db);
    query.prepare("UPDATE triagem SET status = :status WHERE id = :id");
    query.bindValue(":status", status);
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "ERRO NO SQLITE (atualizarStatus):" << query.lastError().text();
        return false;
    }
    return true;
}