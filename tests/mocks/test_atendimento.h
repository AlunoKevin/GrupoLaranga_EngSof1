#ifndef TEST_ATENDIMENTO_H
#define TEST_ATENDIMENTO_H

#include <QObject>
#include <QtTest>
#include "MockAtendimentoRepository.h"
#include "../../CliniGestLogic/services/servicoatendimento.h"

class TestAtendimento : public QObject
{
    Q_OBJECT

private:
    bool executarAtendimentoValido();
    bool executarAtendimentoSemDiagnostico();
    bool executarAtendimentoSemPrescricao();

private slots:
    void registrar_atendimento_valido();
    void registrar_atendimento_sem_diagnostico();
    void registrar_atendimento_sem_prescricao();
};

#endif // TEST_ATENDIMENTO_H