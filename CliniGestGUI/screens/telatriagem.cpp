#include "telatriagem.h"
#include "ui_telatriagem.h" 
#include <QMessageBox>
#include "../../CliniGestLogic/models/triagem.h"

TelaTriagem::TelaTriagem(SistemaFacade* facade, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TelaTriagem),
    m_facade(facade)
{
    ui->setupUi(this);
}

TelaTriagem::~TelaTriagem()
{
    delete ui;
}

void TelaTriagem::on_btnBuscar_clicked() {
    QString nomeBusca = ui->txtNomePaciente->text(); 
    
    if(nomeBusca.isEmpty()) {
        QMessageBox::warning(this, "Aviso", "Digite o nome do paciente para buscar.");
        return;
    }

    bool temConsulta = m_facade->verificarPacienteAgendado(nomeBusca);

    if (temConsulta) {
        QMessageBox::information(this, "Sucesso", "Paciente localizado nos agendamentos de hoje. Pode prosseguir!");
    } else {
        QMessageBox::warning(this, "Aviso", "Não há consultas agendadas para este paciente na data de hoje.");
    }
}

void TelaTriagem::on_btnSalvarTriagem_clicked()
{
    QString nome = ui->txtNomePaciente->text(); 
    QString pressao = ui->txtPressao->text();
    double temp = ui->txtTemperatura->value();
    double peso = ui->txtPeso->value();
    int urgencia = ui->cbUrgencia->currentIndex();

    Triagem dados(nome, pressao, temp, peso, urgencia);

    bool sucesso = m_facade->registrarTriagem(dados);
    
    if (sucesso) {
        QMessageBox::information(this, "Sucesso", "Triagem registrada!");
        this->close(); 
    } else {
        QMessageBox::warning(this, "Erro", "Falha ao registrar triagem.");
    }
}