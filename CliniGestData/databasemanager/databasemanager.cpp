#include "databasemanager.h"
#include <QSqlDatabase>

DatabaseManager::DatabaseManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("clinigest.db");
    db.open();
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
