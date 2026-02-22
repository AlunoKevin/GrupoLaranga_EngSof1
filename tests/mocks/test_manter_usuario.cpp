#include <QtTest>
#include "MockUsuarioRepository.h" // Aquele que criamos antes
#include "../CliniGestLogic/services/servicousuario.h"

class TestManterUsuario : public QObject {
    Q_OBJECT

private slots:
    void initTestCase() {
        // Inicialização global se necessário
    }

    void test_alterar_dados_logado() {
        MockUsuarioRepository repo;
        ServicoUsuario servico(&repo);
        
        // Simula um usuário que já existe
        Usuario* user = new Usuario(1, "Juliana", "123", "old@email.com", "ju", "123", "Medico");
        repo.salvar(user);
        servico.setUsuarioLogado(user);

        // Ação de Manter Cadastro
        bool res = servico.atualizarDadosPessoais(1, "Juliana Nova", "new@email.com");

        QVERIFY(res);
        QCOMPARE(repo.buscarPorId(1)->getNome(), QString("Juliana Nova"));
    }
};

// QTEST_APPLESS_MAIN(TestManterUsuario)
#include "test_manter_usuario.moc"