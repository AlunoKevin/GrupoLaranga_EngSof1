#include <QApplication>
#include "mainwindow.h"
#include "screens/telalogin.h"
#include "../CliniGestData/databasemanager/databasemanager.h"
#include "../CliniGestData/repositories/SqlConsultaRepository.h"
#include "../CliniGestData/repositories/SqlTriagemRepository.h"
#include "../CliniGestLogic/facade/sistemafacade.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 1. Singleton do Banco
    QSqlDatabase db = DatabaseManager::instance().getDatabase();

    // 2. Repositórios
    SqlConsultaRepository consultaRepo(db);
    SqlTriagemRepository triagemRepo(db);

    // 3. Fachada
    SistemaFacade facade(&consultaRepo, &triagemRepo);

    // 4. Fluxo Seguro: Login -> MainWindow
    TelaLogin login(&facade);
    
    if (login.exec() == QDialog::Accepted) {
        MainWindow w(&facade);
        w.show();
        return a.exec();
    }

    return 0;
}