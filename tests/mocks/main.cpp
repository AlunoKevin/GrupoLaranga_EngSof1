#include <QtTest>
#include "test_agendamento.cpp"
#include "test_triagem.cpp"

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
    return status;
}