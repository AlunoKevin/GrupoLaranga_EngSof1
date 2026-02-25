#include "telalogin.h"
#include "ui_telalogin.h"
#include "telaprincipaladmin.h" 
#include <QMessageBox>           


TelaLogin::TelaLogin(SistemaFacade *facade, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TelaLogin)
    , facade(facade) 
{
    ui->setupUi(this);
}

TelaLogin::~TelaLogin()
{
    delete ui;
}


void TelaLogin::on_btnEntrar_clicked()
{
    QString usuarioDigitado = ui->editUsuario->text(); 
    QString senhaDigitada = ui->editSenha->text();     

    bool autenticado = facade->autenticar(usuarioDigitado, senhaDigitada);

    if (autenticado) {
        TelaPrincipalAdmin *admin = new TelaPrincipalAdmin(this->facade);
        admin->show();
        this->close();
    }
    else {
        QMessageBox::warning(this, "Erro de Acesso", "Usuário ou senha incorretos!");
    }
}