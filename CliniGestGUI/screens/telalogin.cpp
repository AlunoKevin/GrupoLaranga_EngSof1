#include "telalogin.h"
#include "ui_telalogin.h"
#include <QMessageBox>

TelaLogin::TelaLogin(SistemaFacade* facade, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaLogin),
    m_facade(facade)
{
    ui->setupUi(this);
}

TelaLogin::~TelaLogin()
{
    delete ui;
}

void TelaLogin::on_btnLogin_clicked()
{
    QString user = ui->editUsuario->text();
    QString pass = ui->editSenha->text();

    if(m_facade->autenticar(user, pass)) {
        this->accept(); // Isso é crucial! Retorna "Accepted" para o main.cpp
    } else {
        QMessageBox::warning(this, "Erro de Acesso", "Usuário ou senha incorretos.\nTente: admin / 1234");
    }
}