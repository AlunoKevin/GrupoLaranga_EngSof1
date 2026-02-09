/**
 * @file telatriagem.h
 * @author Juliana (Grupo Laranja)
 * @brief Interface para realização de triagem clínica.
 */

#ifndef TELATRIAGEM_H
#define TELATRIAGEM_H

#include <QWidget>
#include "../../CliniGestLogic/facade/sistemafacade.h"

namespace Ui {
class TelaTriagem;
}

/**
 * @class TelaTriagem
 * @brief Classe responsável por gerenciar a tela de entrada de dados da triagem.
 * * Esta classe coleta informações como pressão, temperatura e peso,
 * validando-os através do SistemaFacade.
 */
class TelaTriagem : public QWidget
{
    Q_OBJECT

public:
    // recebe o Facade para acessar a lógica
    explicit TelaTriagem(SistemaFacade* facade, QWidget *parent = nullptr);
    ~TelaTriagem();

private slots:
    void on_btnSalvarTriagem_clicked();

private:
    Ui::TelaTriagem *ui;
    SistemaFacade* m_facade;
};

#endif // TELATRIAGEM_H