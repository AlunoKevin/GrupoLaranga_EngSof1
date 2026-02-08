#ifndef TELALOGIN_H
#define TELALOGIN_H

#include <QDialog>
#include "../../CliniGestLogic/facade/sistemafacade.h"

namespace Ui {
class TelaLogin;
}

class TelaLogin : public QDialog
{
    Q_OBJECT

public:
    explicit TelaLogin(SistemaFacade* facade, QWidget *parent = nullptr);
    ~TelaLogin();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::TelaLogin *ui;
    SistemaFacade* m_facade;
};

#endif // TELALOGIN_H