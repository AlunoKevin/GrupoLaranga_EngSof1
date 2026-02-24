#include <QtTest>
#include "test_agendamento.h"
#include "test_triagem.h"
#include "test_manter_usuario.h"

int main(int argc, char *argv[])
{
    int status = 0;
    {
        TestAgendamento tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    {
        TestTriagem tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    {
        TestManterUsuario tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    return status;
}