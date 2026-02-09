/********************************************************************************
** Form generated from reading UI file 'telatriagem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELATRIAGEM_H
#define UI_TELATRIAGEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelaTriagem
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *txtPressao;
    QDoubleSpinBox *txtTemperatura;
    QDoubleSpinBox *txtPeso;
    QComboBox *cbUrgencia;
    QPushButton *btnSalvarTriagem;
    QLabel *label_5;
    QLabel *lblPaciente;
    QLineEdit *txtNomePaciente;
    QPushButton *btnBuscarPaciente;

    void setupUi(QWidget *TelaTriagem)
    {
        if (TelaTriagem->objectName().isEmpty())
            TelaTriagem->setObjectName(QString::fromUtf8("TelaTriagem"));
        TelaTriagem->resize(398, 473);
        label = new QLabel(TelaTriagem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 110, 63, 20));
        label_2 = new QLabel(TelaTriagem);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 190, 91, 20));
        label_3 = new QLabel(TelaTriagem);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 260, 63, 20));
        label_4 = new QLabel(TelaTriagem);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 340, 91, 20));
        txtPressao = new QLineEdit(TelaTriagem);
        txtPressao->setObjectName(QString::fromUtf8("txtPressao"));
        txtPressao->setGeometry(QRect(30, 140, 81, 28));
        txtTemperatura = new QDoubleSpinBox(TelaTriagem);
        txtTemperatura->setObjectName(QString::fromUtf8("txtTemperatura"));
        txtTemperatura->setGeometry(QRect(30, 220, 81, 29));
        txtPeso = new QDoubleSpinBox(TelaTriagem);
        txtPeso->setObjectName(QString::fromUtf8("txtPeso"));
        txtPeso->setGeometry(QRect(30, 290, 81, 29));
        cbUrgencia = new QComboBox(TelaTriagem);
        cbUrgencia->addItem(QString());
        cbUrgencia->addItem(QString());
        cbUrgencia->addItem(QString());
        cbUrgencia->addItem(QString());
        cbUrgencia->setObjectName(QString::fromUtf8("cbUrgencia"));
        cbUrgencia->setGeometry(QRect(30, 380, 82, 28));
        btnSalvarTriagem = new QPushButton(TelaTriagem);
        btnSalvarTriagem->setObjectName(QString::fromUtf8("btnSalvarTriagem"));
        btnSalvarTriagem->setGeometry(QRect(150, 420, 101, 29));
        label_5 = new QLabel(TelaTriagem);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 10, 141, 20));
        lblPaciente = new QLabel(TelaTriagem);
        lblPaciente->setObjectName(QString::fromUtf8("lblPaciente"));
        lblPaciente->setGeometry(QRect(30, 60, 63, 20));
        txtNomePaciente = new QLineEdit(TelaTriagem);
        txtNomePaciente->setObjectName(QString::fromUtf8("txtNomePaciente"));
        txtNomePaciente->setGeometry(QRect(100, 60, 141, 28));
        btnBuscarPaciente = new QPushButton(TelaTriagem);
        btnBuscarPaciente->setObjectName(QString::fromUtf8("btnBuscarPaciente"));
        btnBuscarPaciente->setGeometry(QRect(260, 60, 90, 29));

        retranslateUi(TelaTriagem);

        QMetaObject::connectSlotsByName(TelaTriagem);
    } // setupUi

    void retranslateUi(QWidget *TelaTriagem)
    {
        TelaTriagem->setWindowTitle(QCoreApplication::translate("TelaTriagem", "Form", nullptr));
        label->setText(QCoreApplication::translate("TelaTriagem", "Press\303\243o", nullptr));
        label_2->setText(QCoreApplication::translate("TelaTriagem", "Temperatura", nullptr));
        label_3->setText(QCoreApplication::translate("TelaTriagem", "Peso", nullptr));
        label_4->setText(QCoreApplication::translate("TelaTriagem", "Classifica\303\247\303\243o", nullptr));
        txtTemperatura->setSuffix(QCoreApplication::translate("TelaTriagem", "\302\272C", nullptr));
        txtPeso->setSuffix(QCoreApplication::translate("TelaTriagem", "kg", nullptr));
        cbUrgencia->setItemText(0, QCoreApplication::translate("TelaTriagem", "Verde", nullptr));
        cbUrgencia->setItemText(1, QCoreApplication::translate("TelaTriagem", "Amarelo", nullptr));
        cbUrgencia->setItemText(2, QCoreApplication::translate("TelaTriagem", "Laranja", nullptr));
        cbUrgencia->setItemText(3, QCoreApplication::translate("TelaTriagem", "Vermelho", nullptr));

        btnSalvarTriagem->setText(QCoreApplication::translate("TelaTriagem", "Salvar Triagem", nullptr));
        label_5->setText(QCoreApplication::translate("TelaTriagem", "Registrar Triagem", nullptr));
        lblPaciente->setText(QCoreApplication::translate("TelaTriagem", "Paciente:", nullptr));
        btnBuscarPaciente->setText(QCoreApplication::translate("TelaTriagem", "Buscar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TelaTriagem: public Ui_TelaTriagem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELATRIAGEM_H
