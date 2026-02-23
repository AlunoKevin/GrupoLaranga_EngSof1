#include <QApplication>
#include "mainwindow.h"

#include "../CliniGestData/databasemanager/databasemanager.h"
#include "../CliniGestData/repositories/SqlConsultaRepository.h"
#include "../CliniGestData/repositories/SqlTriagemRepository.h"
#include "../CliniGestData/repositories/SqlAtendimentoRepository.h"
#include "../CliniGestLogic/facade/sistemafacade.h"
#include "../CliniGestData/repositories/SqlUsuarioRepository.h"
#include "../CliniGestLogic/services/servicousuario.h"

#include "screens/telaagendamento.h"
#include "screens/telatriagem.h"
#include "screens/telaatendimento.h"
#include "screens/telaadminusuarios.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = DatabaseManager::instance().getDatabase();

    SqlConsultaRepository consultaRepo(db);
    SqlTriagemRepository triagemRepo(db);
    SqlAtendimentoRepository atendimentoRepo(db);

    // Instancia a Fachada Única com os 3 repositórios
   // SistemaFacade facade(&consultaRepo, &triagemRepo, &atendimentoRepo);


    SqlUsuarioRepository usuarioRepo;
    ServicoUsuario usuarioServico(&usuarioRepo);

    SistemaFacade facade(
        &consultaRepo,
        &triagemRepo,
        &atendimentoRepo,
        &usuarioRepo,
        &usuarioServico
    );

    //TelaAgendamento w(&facade);
   // w.show();

   // TelaTriagem t(&facade);
   // t.show();

    //TelaAtendimento at(&facade);
   // at.show();

    TelaAdminUsuarios admin(&facade);
    admin.show();

    return a.exec();
}