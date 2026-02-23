#include "telaadminusuarios.h"
#include "ui_telaadminusuarios.h"
#include <QMessageBox>

TelaAdminUsuarios::TelaAdminUsuarios(SistemaFacade* facade, QWidget *parent)
    : QWidget(parent),
      ui(new Ui::TelaAdminUsuarios),
      m_facade(facade)
{
    ui->setupUi(this);
}

TelaAdminUsuarios::~TelaAdminUsuarios()
{
    delete ui;
}

void TelaAdminUsuarios::on_btnCadastrar_clicked()
{
    Usuario* u = new Usuario(
        0,
        ui->editNome->text(),
        ui->editCpf->text(),
        ui->editEmail->text(),
        ui->editLogin->text(),
        ui->editSenha->text(),
        ui->comboPerfil->currentText()
    );

    if (m_facade->cadastrarUsuario(u)) {
        QMessageBox::information(this, "Sucesso", "Usuário cadastrado!");
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao cadastrar usuário.");
    }
}

void TelaAdminUsuarios::on_btnAtualizar_clicked()
{
    int id = ui->editId->text().toInt();

    bool ok = m_facade->atualizarDadosUtilizador(
        id,
        ui->editNovoNome->text(),
        ui->editNovoEmail->text()
    );

    if (ok)
        QMessageBox::information(this, "Sucesso", "Dados atualizados!");
    else
        QMessageBox::warning(this, "Erro", "Usuário não encontrado.");
}

void TelaAdminUsuarios::on_btnAlterarSenha_clicked()
{
    int id = ui->editId->text().toInt();

    bool ok = m_facade->alterarSenha(
        id,
        ui->editNovaSenha->text()
    );

    if (ok)
        QMessageBox::information(this, "Sucesso", "Senha alterada!");
    else
        QMessageBox::warning(this, "Erro", "Erro ao alterar senha.");
}