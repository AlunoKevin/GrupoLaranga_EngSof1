#ifndef TEST_TRIAGEM_H
#define TEST_TRIAGEM_H

#include <QObject>
#include <QtTest>

class TestTriagem : public QObject
{
    Q_OBJECT

private slots:
    void test_registrar_triagem_valida();
    void test_validar_temperatura_perigosa();
};

#endif