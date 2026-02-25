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
#include "screens/telalogin.h" // <-- 1. Adicione este include

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = DatabaseManager::instance().getDatabase();

    SqlConsultaRepository consultaRepo(db);
    SqlTriagemRepository triagemRepo(db);
    SqlAtendimentoRepository atendimentoRepo(db);

    SqlUsuarioRepository usuarioRepo;
    ServicoUsuario usuarioServico(&usuarioRepo);

    // Instancia a Fachada Única com todos os repositórios
    SistemaFacade facade(
        &consultaRepo,
        &triagemRepo,
        &atendimentoRepo,
        &usuarioRepo,
        &usuarioServico
    );

    // 2. Comente ou remova a abertura direta da tela de admin
    // TelaAdminUsuarios admin(&facade);
    // admin.show();

    // 3. Inicie pela Tela de Login passando a fachada
    TelaLogin login(&facade); 
    login.show();

    return a.exec();
}