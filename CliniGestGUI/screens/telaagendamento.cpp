#include "telaagendamento.h"
#include "ui_telaagendamento.h"

TelaAgendamento::TelaAgendamento(SistemaFacade* facade, QWidget *parent)
    : QWidget(parent),
      ui(new Ui::TelaAgendamento),
      m_facade(facade)
{
    ui->setupUi(this);
}

TelaAgendamento::~TelaAgendamento()
{
    delete ui;
}


void TelaAgendamento::on_btnAgendar_clicked()
{
    // código será implementado depois
}