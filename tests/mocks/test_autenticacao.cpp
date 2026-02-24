#include <QtTest>
#include <QCoreApplication>

// Inclui a sua lógica
#include "../../CliniGestLogic/facade/sistemafacade.h"
#include "../../CliniGestLogic/services/servicousuario.h"
#include "../../CliniGestLogic/models/usuario.h"
#include "MockUsuarioRepository.h"

class TestAutenticacao : public QObject
{
    Q_OBJECT

private slots:
    void testLoginComSucesso();
    void testLoginFalhaSenhaErrada();
    void testLoginFalhaUsuarioInexistente();
    void testEncerramentoDeSessao();
};

void TestAutenticacao::testLoginComSucesso()
{
    MockUsuarioRepository repo;
    ServicoUsuario servico(&repo);
    SistemaFacade facade(nullptr, nullptr, nullptr, &repo, &servico);

    Usuario* user = new Usuario(1, "Hugo", "111.222.333-44", "hugo@teste.com", "hugo123", "senhaSegura", "Admin");
    repo.salvar(user);

    bool resultado = facade.autenticar("hugo123", "senhaSegura");

    QVERIFY2(resultado == true, "O login com credenciais corretas deve retornar true.");
    QVERIFY2(facade.buscarUtilizadorLogado() != nullptr, "O usuario logado nao deve ser nulo apos o login.");
    QCOMPARE(facade.buscarUtilizadorLogado()->getLogin(), QString("hugo123"));
}

void TestAutenticacao::testLoginFalhaSenhaErrada()
{
    MockUsuarioRepository repo;
    ServicoUsuario servico(&repo);
    SistemaFacade facade(nullptr, nullptr, nullptr, &repo, &servico);

    Usuario* user = new Usuario(1, "Hugo", "111.222.333-44", "hugo@teste.com", "hugo123", "senhaSegura", "Admin");
    repo.salvar(user);

    bool resultado = facade.autenticar("hugo123", "senhaErrada123");

    QVERIFY2(resultado == false, "O login com senha incorreta deve retornar false.");
    QVERIFY2(facade.buscarUtilizadorLogado() == nullptr, "Nenhum usuario deve estar logado apos uma falha.");
}

void TestAutenticacao::testLoginFalhaUsuarioInexistente()
{
    MockUsuarioRepository repo;
    ServicoUsuario servico(&repo);
    SistemaFacade facade(nullptr, nullptr, nullptr, &repo, &servico);

    bool resultado = facade.autenticar("fantasma", "1234");

    QVERIFY2(resultado == false, "O login de um usuario inexistente deve retornar false.");
}

void TestAutenticacao::testEncerramentoDeSessao()
{
    MockUsuarioRepository repo;
    ServicoUsuario servico(&repo);
    SistemaFacade facade(nullptr, nullptr, nullptr, &repo, &servico);

    Usuario* user = new Usuario(1, "Hugo", "111.222.333-44", "hugo@teste.com", "hugo123", "senhaSegura", "Admin");
    repo.salvar(user);

    facade.autenticar("hugo123", "senhaSegura");
    QVERIFY(facade.buscarUtilizadorLogado() != nullptr);

    facade.logout();

    QVERIFY2(facade.buscarUtilizadorLogado() == nullptr, "A sessao deve estar vazia apos o logout.");
}

QTEST_MAIN(TestAutenticacao)
#include "test_autenticacao.moc"