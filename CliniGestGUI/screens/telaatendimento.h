#ifndef TELAATENDIMENTO_H
#define TELAATENDIMENTO_H

#include <QWidget>
#include "../../CliniGestLogic/facade/sistemafacade.h"

namespace Ui {
class TelaAtendimento;
}

class TelaAtendimento : public QWidget
{
    Q_OBJECT

public:
    explicit TelaAtendimento(SistemaFacade* facade, QWidget *parent = nullptr);
    ~TelaAtendimento();

private slots:
    void on_btnSalvar_clicked();
    void on_btnFinalizar_clicked(); 
    void on_btnSair_clicked();

private:
    Ui::TelaAtendimento *ui;
    SistemaFacade* m_facade;
    
    bool salvarDados(); 
};

#endif // TELAATENDIMENTO_H