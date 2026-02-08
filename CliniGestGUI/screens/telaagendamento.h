/**
 * @file telaagendamento.h
 * @author Kevin (Grupo Laranja)
 * @brief Interface para realização de agendamento clínico.
 */

#ifndef TELAAGENDAMENTO_H
#define TELAAGENDAMENTO_H

#include <QWidget>
#include "../../CliniGestLogic/facade/sistemafacade.h"

namespace Ui {
class TelaAgendamento;
}

/**
 * @class TelaAgendamento
 * @brief Classe responsável por gerenciar a tela de entrada de dados do agendamento.
 * Esta classe coleta informações como data, hora e paciente,
 * validando-os através do SistemaFacade.
 */
class TelaAgendamento : public QWidget
{
    Q_OBJECT

public:
    explicit TelaAgendamento(SistemaFacade* facade, QWidget *parent = nullptr);
    ~TelaAgendamento();

private:
    Ui::TelaAgendamento *ui;
    SistemaFacade* m_facade;

private slots:
    void on_btnAgendar_clicked();
};

#endif // TELAAGENDAMENTO_H
