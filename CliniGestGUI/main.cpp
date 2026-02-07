#include <QApplication>
#include "mainwindow.h"

#include "../CliniGestData/databasemanager/databasemanager.h"
#include "../CliniGestData/repositories/SqlConsultaRepository.h"
#include "../CliniGestLogic/facade/sistemafacade.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Get database from singleton
    QSqlDatabase db = DatabaseManager::instance().getDatabase();

    // Create repository
    SqlConsultaRepository repo(db);

    // Create facade
    SistemaFacade facade(&repo);

    // Create main window
    MainWindow w(&facade);
    w.show();

    return a.exec();
}
