#include "databasemanager.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("clinigest.db");

    if (!db.open()) {
        qDebug() << "Erro ao abrir banco:" << db.lastError().text();
        return;
    }

    criarTabelasSeNaoExistirem();
}

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager instance;
    return instance;
}

QSqlDatabase DatabaseManager::getDatabase()
{
    return db;
}
// lida com a criacao inicial caso dee bo no script sql
void DatabaseManager::criarTabelasSeNaoExistirem()
{
    QSqlQuery query;

    // =========================
    // TABELA USUARIOS
    // =========================
    query.exec(
        "CREATE TABLE IF NOT EXISTS usuarios ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "nome TEXT NOT NULL,"
        "cpf TEXT NOT NULL UNIQUE,"
        "email TEXT NOT NULL,"
        "login TEXT NOT NULL UNIQUE,"
        "senha TEXT NOT NULL,"
        "perfil TEXT NOT NULL"
        ");"
    );

    // =========================
    // TABELA CONSULTAS
    // =========================
    query.exec(
        "CREATE TABLE IF NOT EXISTS consultas ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "data TEXT NOT NULL,"
        "hora TEXT NOT NULL,"
        "paciente_nome TEXT NOT NULL,"
        "medico_id INTEGER,"
        "FOREIGN KEY (medico_id) REFERENCES usuarios(id)"
        ");"
    );

    // =========================
    // TABELA TRIAGENS
    // =========================
    query.exec(
        "CREATE TABLE IF NOT EXISTS triagens ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "consulta_id INTEGER,"
        "enfermeiro_id INTEGER,"
        "pressao TEXT,"
        "temperatura REAL,"
        "sintomas TEXT,"
        "observacoes TEXT,"
        "FOREIGN KEY (consulta_id) REFERENCES consultas(id),"
        "FOREIGN KEY (enfermeiro_id) REFERENCES usuarios(id)"
        ");"
    );

    // =========================
    // TABELA ATENDIMENTOS
    // =========================
    query.exec(
        "CREATE TABLE IF NOT EXISTS atendimentos ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "consulta_id INTEGER,"
        "medico_id INTEGER,"
        "diagnostico TEXT,"
        "prescricao TEXT,"
        "observacoes TEXT,"
        "data_atendimento TEXT,"
        "FOREIGN KEY (consulta_id) REFERENCES consultas(id),"
        "FOREIGN KEY (medico_id) REFERENCES usuarios(id)"
        ");"
    );

    qDebug() << "Banco verificado/criado com sucesso.";
}