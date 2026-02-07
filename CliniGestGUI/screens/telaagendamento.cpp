#include "telaagendamento.h"
#include "ui_telaagendamento.h"
#include <QMessageBox>

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
    Consulta consulta;

    consulta.setPacienteId(ui->spinPacienteId->value());
    consulta.setMedicoId(ui->spinMedicoId->value());
    consulta.setDataHora(ui->dateTimeEdit->dateTime());

    bool ok = m_facade->agendarConsulta(consulta);

    if (ok)
        QMessageBox::information(this, "Sucesso", "Consulta agendada!");
    else
        QMessageBox::warning(this, "Erro", "Falha ao agendar.");
}
