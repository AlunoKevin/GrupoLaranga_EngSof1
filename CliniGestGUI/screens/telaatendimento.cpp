#include "telaatendimento.h"
#include "ui_telaatendimento.h"
#include <QMessageBox>

TelaAtendimento::TelaAtendimento(SistemaFacade* facade, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TelaAtendimento),
    m_facade(facade)
{
    ui->setupUi(this);
}

TelaAtendimento::~TelaAtendimento()
{
    delete ui;
}

bool TelaAtendimento::salvarDados() {
    QString diagnostico = ui->txtDiagnostico->text();
    QString prescricao = ui->txtPrescricao->toPlainText();
    QString exames = ui->txtExames->toPlainText();
    QString observacoes = ui->txtObservacoes->toPlainText();

    if (diagnostico.isEmpty() || prescricao.isEmpty()) {
        QMessageBox::warning(this, "Aviso", "Diagnóstico e Prescrição são obrigatórios!");
        return false;
    }

    Atendimento novoAtendimento(1, diagnostico, prescricao, exames, observacoes);

    if (m_facade->registrarAtendimento(novoAtendimento)) {
        return true;
    } else {
        QMessageBox::critical(this, "Erro", "Falha ao salvar no banco de dados.");
        return false;
    }
}

void TelaAtendimento::on_btnSalvar_clicked()
{
    if (salvarDados()) {
        QMessageBox::information(this, "Salvo", "Dados salvos com sucesso! Você pode continuar editando.");
    }
}

// NOVO: Botão Finalizar
void TelaAtendimento::on_btnFinalizar_clicked()
{
    // Tenta salvar. Se der certo, avisa e fecha.
    if (salvarDados()) {
        QMessageBox::information(this, "Concluído", "Atendimento finalizado com sucesso!");
        this->close(); // 
    }
}

void TelaAtendimento::on_btnSair_clicked()
{
    this->close();
}