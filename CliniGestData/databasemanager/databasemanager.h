

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>

class DatabaseManager
{
public:
    static DatabaseManager& instance();

    QSqlDatabase getDatabase();
    

private:
    DatabaseManager();
    void criarTabelasSeNaoExistirem();
    QSqlDatabase db;
};

#endif
