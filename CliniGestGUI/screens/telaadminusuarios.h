#ifndef TELAADMINUSUARIOS_H
#define TELAADMINUSUARIOS_H

#include <QWidget>
#include "../CliniGestLogic/facade/sistemafacade.h"

namespace Ui {
class TelaAdminUsuarios;
}

class TelaAdminUsuarios : public QWidget
{
    Q_OBJECT

public:
    explicit TelaAdminUsuarios(SistemaFacade* facade, QWidget *parent = nullptr);
    ~TelaAdminUsuarios();

private slots:
    void on_btnCadastrar_clicked();
    void on_btnAtualizar_clicked();
    void on_btnAlterarSenha_clicked();

private:
    Ui::TelaAdminUsuarios *ui;
    SistemaFacade* m_facade;
};

#endif