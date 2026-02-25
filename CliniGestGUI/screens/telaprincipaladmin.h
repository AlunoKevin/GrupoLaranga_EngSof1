#ifndef TELAPRINCIPALADMIN_H
#define TELAPRINCIPALADMIN_H

#include <QWidget>
#include "../CliniGestLogic/facade/sistemafacade.h" 

namespace Ui {
class TelaPrincipalAdmin;
}

class TelaPrincipalAdmin : public QWidget
{
    Q_OBJECT

public:
    explicit TelaPrincipalAdmin(SistemaFacade *facade, QWidget *parent = nullptr);
    ~TelaPrincipalAdmin();

private slots:
    void on_user_clicked();
    void on_tri_clicked();
    void on_agend_clicked();
    void on_aten_clicked();
    void on_sair_clicked(); 

private:
    Ui::TelaPrincipalAdmin *ui;
    SistemaFacade *facade; 
};

#endif // TELAPRINCIPALADMIN_H