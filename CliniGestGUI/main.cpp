#include <QApplication>
#include "mainwindow.h"

#include "../CliniGestData/databasemanager/databasemanager.h"
#include "../CliniGestData/repositories/SqlConsultaRepository.h"
#include "../CliniGestData/repositories/SqlTriagemRepository.h"
#include "../CliniGestLogic/facade/sistemafacade.h"
#include "screens/telaagendamento.h"
#include "screens/telatriagem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Get database from singleton
    QSqlDatabase db = DatabaseManager::instance().getDatabase();

    // Create repository
    SqlConsultaRepository consultaRepo(db);
    SqlTriagemRepository triagemRepo(db);

    // Create facade
    SistemaFacade facade(&consultaRepo, &triagemRepo);

    // Create main window
    //MainWindow w(&facade);
    //w.show();
    
    // Create agendamento screen directly
    TelaAgendamento w(&facade);
    w.show();

    // Create triagem screen directly
    TelaTriagem t(&facade);
    t.show();

    return a.exec();
}
