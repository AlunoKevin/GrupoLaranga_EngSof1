#include "telatriagem.h"
#include "ui_telatriagem.h" // <-- ESTA LINHA É A CHAVE PARA O ERRO SUMIR
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
    // Coleta dados da UI
    QString pressao = ui->txtPressao->text();
    double temp = ui->txtTemperatura->value();
    double peso = ui->txtPeso->value();
    int urgencia = ui->cbUrgencia->currentIndex();

    // Cria o objeto para passar para a lógica (resolvendo o erro de argumentos)
    Triagem dados(pressao, temp, peso, urgencia);

    if (m_facade->registrarTriagem(dados)) {
        QMessageBox::information(this, "Sucesso", "Triagem registrada!");
        this->close();
    } else {
        QMessageBox::warning(this, "Erro", "Falha ao registrar triagem.");
    }
}