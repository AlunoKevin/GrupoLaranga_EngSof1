/********************************************************************************
** Form generated from reading UI file 'telaagendamento.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELAAGENDAMENTO_H
#define UI_TELAAGENDAMENTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelaAgendamento
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *editPaciente_;
    QLabel *label_2;
    QLineEdit *editMedico_;
    QLabel *label_4;
    QDateEdit *editData_;
    QLabel *label_5;
    QTimeEdit *editHora_;
    QPushButton *btnAgendar;

    void setupUi(QWidget *TelaAgendamento)
    {
        if (TelaAgendamento->objectName().isEmpty())
            TelaAgendamento->setObjectName("TelaAgendamento");
        TelaAgendamento->resize(503, 375);
        verticalLayout_3 = new QVBoxLayout(TelaAgendamento);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(TelaAgendamento);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        label = new QLabel(TelaAgendamento);
        label->setObjectName("label");

        verticalLayout_3->addWidget(label);

        editPaciente_ = new QLineEdit(TelaAgendamento);
        editPaciente_->setObjectName("editPaciente_");

        verticalLayout_3->addWidget(editPaciente_);

        label_2 = new QLabel(TelaAgendamento);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2);

        editMedico_ = new QLineEdit(TelaAgendamento);
        editMedico_->setObjectName("editMedico_");

        verticalLayout_3->addWidget(editMedico_);

        label_4 = new QLabel(TelaAgendamento);
        label_4->setObjectName("label_4");

        verticalLayout_3->addWidget(label_4);

        editData_ = new QDateEdit(TelaAgendamento);
        editData_->setObjectName("editData_");

        verticalLayout_3->addWidget(editData_);

        label_5 = new QLabel(TelaAgendamento);
        label_5->setObjectName("label_5");

        verticalLayout_3->addWidget(label_5);

        editHora_ = new QTimeEdit(TelaAgendamento);
        editHora_->setObjectName("editHora_");

        verticalLayout_3->addWidget(editHora_);

        btnAgendar = new QPushButton(TelaAgendamento);
        btnAgendar->setObjectName("btnAgendar");

        verticalLayout_3->addWidget(btnAgendar);


        retranslateUi(TelaAgendamento);

        QMetaObject::connectSlotsByName(TelaAgendamento);
    } // setupUi

    void retranslateUi(QWidget *TelaAgendamento)
    {
        TelaAgendamento->setWindowTitle(QCoreApplication::translate("TelaAgendamento", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("TelaAgendamento", "Agendamento de Consulta\n"
"", nullptr));
        label->setText(QCoreApplication::translate("TelaAgendamento", "Paciente", nullptr));
        label_2->setText(QCoreApplication::translate("TelaAgendamento", "M\303\251dico", nullptr));
        editMedico_->setText(QString());
        label_4->setText(QCoreApplication::translate("TelaAgendamento", "Data", nullptr));
        label_5->setText(QCoreApplication::translate("TelaAgendamento", "Hora", nullptr));
        btnAgendar->setText(QCoreApplication::translate("TelaAgendamento", "Agendar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TelaAgendamento: public Ui_TelaAgendamento {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELAAGENDAMENTO_H
