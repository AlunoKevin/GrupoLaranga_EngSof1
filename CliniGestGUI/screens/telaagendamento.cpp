#include "telaagendamento.h"
#include "ui_telaagendamento.h"
#include <QHeaderView>
#include <QMessageBox> // Corrige erro de 'QMessageBox not declared'
#include <QDate>
#include <QTime>

TelaAgendamento::TelaAgendamento(SistemaFacade* facade, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::TelaAgendamento),
    m_facade(facade)
{
    ui->setupUi(this);

    // Configuração da tabela
    QStringList titulos;
    titulos << "ID" << "Paciente" << "Status";
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

TelaAgendamento::~TelaAgendamento()
{
    delete ui;
}

void TelaAgendamento::on_btnAgendar_clicked()
{
    // CORREÇÃO: Usando os nomes com _ no final (como pede o erro)
    QString paciente = ui->editPaciente_->text();
    QString medico   = ui->editMedico_->text();
    QString dataStr  = ui->editData_->text();
    QString horaStr  = ui->editHora_->text();

    // Validação simples
    if (paciente.isEmpty() || medico.isEmpty() ||
        dataStr.isEmpty() || horaStr.isEmpty())
    {
        QMessageBox::warning(this, "Erro", "Preencha todos os campos.");
        return;
    }

    Consulta consulta;

    // Preenchendo os dados (Agora o arquivo .h tem esses métodos)
    consulta.setPaciente(paciente.toStdString());
    consulta.setMedico(medico.toStdString());

    // Convertendo texto para data/hora
    consulta.setData(QDate::fromString(dataStr, "dd/MM/yyyy"));
    consulta.setHorario(QTime::fromString(horaStr, "HH:mm"));

    // Chamada ao sistema
    bool sucesso = m_facade->agendarConsulta(consulta);

    if (sucesso)
    {
        int linha = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(linha);

        // Preenchendo a tabela visual
        ui->tableWidget->setItem(linha, 0, new QTableWidgetItem("Novo"));
        ui->tableWidget->setItem(linha, 1, new QTableWidgetItem(paciente));

        QTableWidgetItem *itemStatus = new QTableWidgetItem("AGENDADO");
        itemStatus->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(linha, 2, itemStatus);

        ui->tableWidget->item(linha, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(linha, 1)->setTextAlignment(Qt::AlignCenter);

        QMessageBox::information(this, "Sucesso", "Consulta agendada!");

        // Limpar campos
        ui->editPaciente_->clear();
        ui->editMedico_->clear();
        ui->editData_->clear();
        ui->editHora_->clear();
    }
    else
    {
        QMessageBox::warning(this, "Erro", "Falha ao agendar consulta.");
    }
}

void TelaAgendamento::on_btnCancelar_clicked()
{
    int linha = ui->tableWidget->currentRow();

    if (linha < 0) {
        QMessageBox::warning(this, "Atenção", "Selecione um paciente na tabela para cancelar.");
        return;
    }

    QTableWidgetItem *itemStatus = ui->tableWidget->item(linha, 2);
    if(itemStatus) {
        itemStatus->setText("CANCELADO");
        itemStatus->setBackground(QColor(Qt::red));
        itemStatus->setForeground(QColor(Qt::white));
    }

    QMessageBox::information(this, "Sucesso", "Agendamento cancelado!");
}
