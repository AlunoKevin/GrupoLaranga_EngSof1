#include "test_manter_usuario.h"
#include "MockUsuarioRepository.h"
#include "../CliniGestLogic/services/servicousuario.h"

void TestManterUsuario::initTestCase() {}

void TestManterUsuario::test_alterar_dados_logado() {
    MockUsuarioRepository repo;
    ServicoUsuario servico(&repo);
    Usuario* user = new Usuario(1, "Juliana", "123", "old@email.com", "ju", "123", "Medico");
    repo.salvar(user);
    servico.setUsuarioLogado(user);

    bool res = servico.atualizarDadosPessoais(1, "Juliana Nova", "new@email.com");
    QVERIFY(res);
    QCOMPARE(repo.buscarPorId(1)->getNome(), QString("Juliana Nova"));
}

void TestManterUsuario::test_cadastrar_novo_usuario() {
    MockUsuarioRepository repo;
    ServicoUsuario servico(&repo);
    Usuario* novo = new Usuario(2, "Kevin", "456", "kevin@email.com", "kevin", "senha123", "Admin");
    
    bool res = repo.salvar(novo);
    QVERIFY(res);
    QCOMPARE(repo.listarTodos().size(), 1);
}

void TestManterUsuario::test_alterar_senha_usuario() {
    MockUsuarioRepository repo;
    ServicoUsuario servico(&repo);
    Usuario* user = new Usuario(1, "Juliana", "123", "old@email.com", "ju", "123", "Medico");
    repo.salvar(user);

    bool res = servico.alterarSenha(1, "novaSenha456"); 
    QVERIFY(res);
    QCOMPARE(repo.buscarPorId(1)->getSenha(), QString("novaSenha456"));
}