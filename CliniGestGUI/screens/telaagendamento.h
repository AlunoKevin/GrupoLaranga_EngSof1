#ifndef TELAAGENDAMENTO_H
#define TELAAGENDAMENTO_H

#include <QWidget>
#include "../../CliniGestLogic/facade/sistemafacade.h"

namespace Ui {
class TelaAgendamento;
}

class TelaAgendamento : public QWidget
{
    Q_OBJECT

public:
    explicit TelaAgendamento(SistemaFacade* facade, QWidget *parent = nullptr);
    ~TelaAgendamento();

private slots:
    void on_btnAgendar_clicked();

private:
    Ui::TelaAgendamento *ui;
    SistemaFacade* m_facade;
};

#endif // TELAAGENDAMENTO_H
