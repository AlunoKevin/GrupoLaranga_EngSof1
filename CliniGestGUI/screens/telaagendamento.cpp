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
    QString paciente = ui->editPaciente->text();
    QString medico   = ui->editMedico->text();
    QString data     = ui->editData->text();
    QString hora     = ui->editHora->text();

    // Simple validation
    if (paciente.isEmpty() || medico.isEmpty() ||
        data.isEmpty() || hora.isEmpty())
    {
        QMessageBox::warning(this, "Erro", "Preencha todos os campos.");
        return;
    }

    // Create Consulta object
    Consulta consulta;
    consulta.setPaciente(paciente.toStdString());
    consulta.setMedico(medico.toStdString());
    consulta.setData(data.toStdString());
    consulta.setHora(hora.toStdString());

    // Call facade
    bool sucesso = m_facade->agendarConsulta(consulta);

    if (sucesso)
    {
        QMessageBox::information(this, "Sucesso", "Consulta agendada!");
    }
    else
    {
        QMessageBox::warning(this, "Erro", "Falha ao agendar consulta.");
    }
}