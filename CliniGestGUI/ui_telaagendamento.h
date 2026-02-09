/********************************************************************************
** Form generated from reading UI file 'telaagendamento.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELAAGENDAMENTO_H
#define UI_TELAAGENDAMENTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelaAgendamento
{
public:
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
    QTableWidget *tableWidget;
    QPushButton *btnCancelar;

    void setupUi(QWidget *TelaAgendamento)
    {
        if (TelaAgendamento->objectName().isEmpty())
            TelaAgendamento->setObjectName(QString::fromUtf8("TelaAgendamento"));
        TelaAgendamento->resize(512, 618);
        label_3 = new QLabel(TelaAgendamento);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(11, 11, 177, 40));
        label = new QLabel(TelaAgendamento);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(11, 58, 55, 20));
        editPaciente_ = new QLineEdit(TelaAgendamento);
        editPaciente_->setObjectName(QString::fromUtf8("editPaciente_"));
        editPaciente_->setGeometry(QRect(11, 85, 471, 28));
        label_2 = new QLabel(TelaAgendamento);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(11, 120, 50, 20));
        editMedico_ = new QLineEdit(TelaAgendamento);
        editMedico_->setObjectName(QString::fromUtf8("editMedico_"));
        editMedico_->setGeometry(QRect(11, 147, 471, 28));
        label_4 = new QLabel(TelaAgendamento);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(11, 182, 32, 20));
        editData_ = new QDateEdit(TelaAgendamento);
        editData_->setObjectName(QString::fromUtf8("editData_"));
        editData_->setGeometry(QRect(11, 209, 471, 29));
        label_5 = new QLabel(TelaAgendamento);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(11, 245, 33, 20));
        editHora_ = new QTimeEdit(TelaAgendamento);
        editHora_->setObjectName(QString::fromUtf8("editHora_"));
        editHora_->setGeometry(QRect(11, 272, 471, 29));
        btnAgendar = new QPushButton(TelaAgendamento);
        btnAgendar->setObjectName(QString::fromUtf8("btnAgendar"));
        btnAgendar->setGeometry(QRect(210, 310, 80, 29));
        tableWidget = new QTableWidget(TelaAgendamento);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 350, 491, 191));
        btnCancelar = new QPushButton(TelaAgendamento);
        btnCancelar->setObjectName(QString::fromUtf8("btnCancelar"));
        btnCancelar->setGeometry(QRect(170, 560, 161, 29));

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
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TelaAgendamento", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TelaAgendamento", "Paciente", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TelaAgendamento", "Status", nullptr));
        btnCancelar->setText(QCoreApplication::translate("TelaAgendamento", "Cancelar selecionado", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TelaAgendamento: public Ui_TelaAgendamento {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELAAGENDAMENTO_H
