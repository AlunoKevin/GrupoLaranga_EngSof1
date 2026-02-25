#ifndef TELALOGIN_H
#define TELALOGIN_H

#include <QWidget>
#include "../CliniGestLogic/facade/sistemafacade.h" 

namespace Ui {
class TelaLogin;
}

class TelaLogin : public QWidget
{
    Q_OBJECT

public:
    explicit TelaLogin(SistemaFacade *facade, QWidget *parent = nullptr);
    ~TelaLogin();

private slots:
    void on_btnEntrar_clicked();

private:
    Ui::TelaLogin *ui;
    SistemaFacade *facade; 
};

#endif // TELALOGIN_H