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

void TelaTriagem::on_btnSalvarTriagem_clicked()
{
    // 1. Pegue o nome do campo que você tem na UI (ex: txtNomePaciente)
    QString nome = ui->txtNomePaciente->text(); 
    QString pressao = ui->txtPressao->text();
    double temp = ui->txtTemperatura->value();
    double peso = ui->txtPeso->value();
    int urgencia = ui->cbUrgencia->currentIndex();

    // 2. Agora passe o 'nome' como primeiro argumento
    Triagem dados(nome, pressao, temp, peso, urgencia);

    if (m_facade->registrarTriagem(dados)) {
        QMessageBox::information(this, "Sucesso", "Triagem registrada!");
        this->close();
    } else {
        QMessageBox::warning(this, "Erro", "Falha ao registrar triagem.");
    }
}