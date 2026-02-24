#ifndef TEST_MANTER_USUARIO_H
#define TEST_MANTER_USUARIO_H

#include <QObject>
#include <QtTest>

class TestManterUsuario : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void test_alterar_dados_logado();
    void test_cadastrar_novo_usuario(); 
    void test_alterar_senha_usuario();   
};

#endif