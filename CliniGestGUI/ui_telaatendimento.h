/********************************************************************************
** Form generated from reading UI file 'telaatendimento.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELAATENDIMENTO_H
#define UI_TELAATENDIMENTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelaAtendimento
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitulo;
    QGroupBox *groupDados;
    QFormLayout *formLayout;
    QLabel *lblDiag;
    QLineEdit *txtDiagnostico;
    QLabel *lblPresc;
    QPlainTextEdit *txtPrescricao;
    QLabel *lblExames;
    QPlainTextEdit *txtExames;
    QLabel *lblObs;
    QPlainTextEdit *txtObservacoes;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSalvar;
    QPushButton *btnFinalizar;
    QPushButton *btnSair;

    void setupUi(QWidget *TelaAtendimento)
    {
        if (TelaAtendimento->objectName().isEmpty())
            TelaAtendimento->setObjectName(QString::fromUtf8("TelaAtendimento"));
        TelaAtendimento->resize(800, 600);
        verticalLayout = new QVBoxLayout(TelaAtendimento);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelTitulo = new QLabel(TelaAtendimento);
        labelTitulo->setObjectName(QString::fromUtf8("labelTitulo"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        labelTitulo->setFont(font);
        labelTitulo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTitulo);

        groupDados = new QGroupBox(TelaAtendimento);
        groupDados->setObjectName(QString::fromUtf8("groupDados"));
        formLayout = new QFormLayout(groupDados);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lblDiag = new QLabel(groupDados);
        lblDiag->setObjectName(QString::fromUtf8("lblDiag"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblDiag);

        txtDiagnostico = new QLineEdit(groupDados);
        txtDiagnostico->setObjectName(QString::fromUtf8("txtDiagnostico"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtDiagnostico);

        lblPresc = new QLabel(groupDados);
        lblPresc->setObjectName(QString::fromUtf8("lblPresc"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblPresc);

        txtPrescricao = new QPlainTextEdit(groupDados);
        txtPrescricao->setObjectName(QString::fromUtf8("txtPrescricao"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtPrescricao);

        lblExames = new QLabel(groupDados);
        lblExames->setObjectName(QString::fromUtf8("lblExames"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lblExames);

        txtExames = new QPlainTextEdit(groupDados);
        txtExames->setObjectName(QString::fromUtf8("txtExames"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txtExames);

        lblObs = new QLabel(groupDados);
        lblObs->setObjectName(QString::fromUtf8("lblObs"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lblObs);

        txtObservacoes = new QPlainTextEdit(groupDados);
        txtObservacoes->setObjectName(QString::fromUtf8("txtObservacoes"));

        formLayout->setWidget(3, QFormLayout::FieldRole, txtObservacoes);


        verticalLayout->addWidget(groupDados);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSalvar = new QPushButton(TelaAtendimento);
        btnSalvar->setObjectName(QString::fromUtf8("btnSalvar"));

        horizontalLayout->addWidget(btnSalvar);

        btnFinalizar = new QPushButton(TelaAtendimento);
        btnFinalizar->setObjectName(QString::fromUtf8("btnFinalizar"));

        horizontalLayout->addWidget(btnFinalizar);

        btnSair = new QPushButton(TelaAtendimento);
        btnSair->setObjectName(QString::fromUtf8("btnSair"));

        horizontalLayout->addWidget(btnSair);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TelaAtendimento);

        QMetaObject::connectSlotsByName(TelaAtendimento);
    } // setupUi

    void retranslateUi(QWidget *TelaAtendimento)
    {
        TelaAtendimento->setWindowTitle(QCoreApplication::translate("TelaAtendimento", "Registro de Atendimento M\303\251dico - CliniGest", nullptr));
        labelTitulo->setText(QCoreApplication::translate("TelaAtendimento", "Atendimento M\303\251dico", nullptr));
        groupDados->setTitle(QCoreApplication::translate("TelaAtendimento", "Prontu\303\241rio Eletr\303\264nico", nullptr));
        lblDiag->setText(QCoreApplication::translate("TelaAtendimento", "Diagn\303\263stico (CID):", nullptr));
        txtDiagnostico->setPlaceholderText(QCoreApplication::translate("TelaAtendimento", "Informe o c\303\263digo CID ou descri\303\247\303\243o...", nullptr));
        lblPresc->setText(QCoreApplication::translate("TelaAtendimento", "Prescri\303\247\303\243o M\303\251dica:", nullptr));
        lblExames->setText(QCoreApplication::translate("TelaAtendimento", "Solicita\303\247\303\243o de Exames:", nullptr));
        lblObs->setText(QCoreApplication::translate("TelaAtendimento", "Observa\303\247\303\265es:", nullptr));
        btnSalvar->setText(QCoreApplication::translate("TelaAtendimento", "Salvar (Ctrl+S)", nullptr));
#if QT_CONFIG(shortcut)
        btnSalvar->setShortcut(QCoreApplication::translate("TelaAtendimento", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        btnFinalizar->setText(QCoreApplication::translate("TelaAtendimento", "Finalizar Atendimento (Enter)", nullptr));
#if QT_CONFIG(shortcut)
        btnFinalizar->setShortcut(QCoreApplication::translate("TelaAtendimento", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        btnFinalizar->setStyleSheet(QCoreApplication::translate("TelaAtendimento", "background-color: #28a745; color: white; font-weight: bold;", nullptr));
        btnSair->setText(QCoreApplication::translate("TelaAtendimento", "Voltar (Esc)", nullptr));
#if QT_CONFIG(shortcut)
        btnSair->setShortcut(QCoreApplication::translate("TelaAtendimento", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class TelaAtendimento: public Ui_TelaAtendimento {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELAATENDIMENTO_H
