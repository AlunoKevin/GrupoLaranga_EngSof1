#include "SqlTriagemRepository.h"

SqlTriagemRepository::SqlTriagemRepository(QSqlDatabase db) : m_db(db) 
{
    QSqlQuery query(m_db);
    query.exec("CREATE TABLE IF NOT EXISTS triagem ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "paciente_nome TEXT, "
               "pressao TEXT, "
               "temperatura REAL, "
               "peso REAL, "
               "urgencia INTEGER)");
}

// A implementação do salvar já estava correta, mas aqui está novamente para referência
bool SqlTriagemRepository::salvar(const Triagem& triagem) {
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO triagem (paciente_nome, pressao, temperatura, peso, urgencia) "
                  "VALUES (:nome, :pressao, :temp, :peso, :urgencia)");

    query.bindValue(":nome", triagem.getPacienteNome()); 
    query.bindValue(":pressao", triagem.getPressao());
    query.bindValue(":temp", triagem.getTemperatura());
    query.bindValue(":peso", triagem.getPeso());
    query.bindValue(":urgencia", triagem.getUrgencia());

    if (!query.exec()) {
        // ESSA LINHA É A CHAVE: Ela vai imprimir o erro no console do Qt Creator
        qDebug() << "ERRO NO SQLITE:" << query.lastError().text();
        return false;
    }
    return true;
}

// Implementação do buscarPorPaciente para o médico ver os dados na tela
Triagem SqlTriagemRepository::buscarPorPaciente(const QString& cpf) {
    QSqlQuery query(m_db);
    // Buscando os 5 campos que o construtor da Triagem espera
    query.prepare("SELECT paciente_nome, pressao, temperatura, peso, urgencia FROM triagem WHERE paciente_nome = :nome ORDER BY id DESC LIMIT 1");
    query.bindValue(":nome", cpf);

    if (query.exec() && query.next()) {
        // O construtor da Triagem espera 5 argumentos: nome, pressao, temp, peso, urgencia
        return Triagem(
            query.value(0).toString(), 
            query.value(1).toString(),
            query.value(2).toDouble(),
            query.value(3).toDouble(),
            query.value(4).toInt()
        );
    }
    return Triagem();
}