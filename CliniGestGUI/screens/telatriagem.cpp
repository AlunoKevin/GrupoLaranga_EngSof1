#include "telatriagem.h"
#include "ui_telatriagem.h" 
#include <QMessageBox>
#include <QDebug>
#include "../../CliniGestLogic/models/triagem.h"

TelaTriagem::TelaTriagem(SistemaFacade* facade, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TelaTriagem),
    m_facade(facade)
{
    ui->setupUi(this);

    connect(ui->btnBuscarPaciente, &QPushButton::clicked, this, &TelaTriagem::on_btnBuscar_clicked);
    // connect(ui->btnSalvarTriagem, &QPushButton::clicked, this, &TelaTriagem::on_btnSalvarTriagem_clicked);
}

TelaTriagem::~TelaTriagem()
{
    delete ui;
}

void TelaTriagem::on_btnBuscar_clicked() {
    qDebug() << "Botão Buscar clicado!";
    QMessageBox::information(this, "Busca", "Funcionalidade de busca sendo integrada...");
}

void TelaTriagem::on_btnSalvarTriagem_clicked()
{
    // qDebug() << "O BOTAO FOI CLICADO!"; // Se isso não aparecer no console, o problema é a conexão

    // Coleta dados da UI
    QString nome = ui->txtNomePaciente->text();
    QString pressao = ui->txtPressao->text();
    double temp = ui->txtTemperatura->value();
    double peso = ui->txtPeso->value();
    int urgencia = ui->cbUrgencia->currentIndex();

    // if(nome.isEmpty()) {
    //     QMessageBox::warning(this, "Aviso", "Por favor, identifique o paciente antes de salvar.");
    //     return;
    // }

    Triagem dados(nome, pressao, temp, peso, urgencia);

    // if (m_facade->registrarTriagem(dados)) {
    //     qDebug() << "Sucesso na Facade";
    //     QMessageBox::information(this, "Sucesso", "Triagem de " + nome + " registrada!");
    //     this->close();
    // } else {
    //     qDebug() << "Falha na Facade";
    //     QMessageBox::warning(this, "Erro", "Falha ao registrar triagem.");
    // }
}