#include "telaprincipaladmin.h"
#include "ui_telaprincipaladmin.h"

// Inclusão de todas as telas que você já organizou na pasta 'screens'
#include "telalogin.h"
#include "telaadminusuarios.h"
#include "telatriagem.h"
#include "telaagendamento.h"
#include "telaatendimento.h"

// O construtor recebe a Fachada vinda da TelaLogin e a armazena
TelaPrincipalAdmin::TelaPrincipalAdmin(SistemaFacade *facade, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TelaPrincipalAdmin),
    facade(facade) 
{
    ui->setupUi(this);
}

TelaPrincipalAdmin::~TelaPrincipalAdmin()
{
    delete ui;
}

// --- Mapeamento dos Botões do Painel ---

// 1. Botão: Gerenciar usuários
void TelaPrincipalAdmin::on_user_clicked() {
    TelaAdminUsuarios *tela = new TelaAdminUsuarios(facade);
    tela->show();
}

// 2. Botão: Triagem
void TelaPrincipalAdmin::on_tri_clicked() {
    TelaTriagem *tela = new TelaTriagem(facade);
    tela->show();
}

// 3. Botão: Agendamento
void TelaPrincipalAdmin::on_agend_clicked() {
    TelaAgendamento *tela = new TelaAgendamento(facade);
    tela->show();
}

// 4. Botão: Atendimento
void TelaPrincipalAdmin::on_aten_clicked() {
    TelaAtendimento *tela = new TelaAtendimento(facade);
    tela->show();
}

// 5. Botão: SAIR
void TelaPrincipalAdmin::on_sair_clicked() {
    TelaLogin *login = new TelaLogin(facade);
    login->show();
    this->close();
}