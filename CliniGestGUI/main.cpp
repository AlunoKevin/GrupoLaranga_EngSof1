#include <QApplication>
#include "mainwindow.h"

#include "../CliniGestData/databasemanager/databasemanager.h"
#include "../CliniGestData/repositories/SqlConsultaRepository.h"
#include "../CliniGestData/repositories/SqlTriagemRepository.h"
#include "../CliniGestData/repositories/SqlAtendimentoRepository.h"
#include "../CliniGestLogic/facade/sistemafacade.h"

#include "screens/telaagendamento.h"
#include "screens/telatriagem.h"
#include "screens/telaatendimento.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = DatabaseManager::instance().getDatabase();

    SqlConsultaRepository consultaRepo(db);
    SqlTriagemRepository triagemRepo(db);
    SqlAtendimentoRepository atendimentoRepo(db);

    // Instancia a Fachada Única com os 3 repositórios
    SistemaFacade facade(&consultaRepo, &triagemRepo, &atendimentoRepo);

    TelaAgendamento w(&facade);
    w.show();

    TelaTriagem t(&facade);
    t.show();

    TelaAtendimento at(&facade);
    at.show();

    return a.exec();
}