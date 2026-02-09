/********************************************************************************
** Form generated from reading UI file 'telalogin.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELALOGIN_H
#define UI_TELALOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TelaLogin
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QLabel *labelUser;
    QLineEdit *editUsuario;
    QLabel *labelPass;
    QLineEdit *editSenha;
    QSpacerItem *verticalSpacer;
    QPushButton *btnLogin;

    void setupUi(QDialog *TelaLogin)
    {
        if (TelaLogin->objectName().isEmpty())
            TelaLogin->setObjectName("TelaLogin");
        TelaLogin->resize(400, 300);
        verticalLayout = new QVBoxLayout(TelaLogin);
        verticalLayout->setObjectName("verticalLayout");
        labelTitle = new QLabel(TelaLogin);
        labelTitle->setObjectName("labelTitle");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        labelUser = new QLabel(TelaLogin);
        labelUser->setObjectName("labelUser");

        verticalLayout->addWidget(labelUser);

        editUsuario = new QLineEdit(TelaLogin);
        editUsuario->setObjectName("editUsuario");

        verticalLayout->addWidget(editUsuario);

        labelPass = new QLabel(TelaLogin);
        labelPass->setObjectName("labelPass");

        verticalLayout->addWidget(labelPass);

        editSenha = new QLineEdit(TelaLogin);
        editSenha->setObjectName("editSenha");
        editSenha->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(editSenha);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnLogin = new QPushButton(TelaLogin);
        btnLogin->setObjectName("btnLogin");

        verticalLayout->addWidget(btnLogin);


        retranslateUi(TelaLogin);

        QMetaObject::connectSlotsByName(TelaLogin);
    } // setupUi

    void retranslateUi(QDialog *TelaLogin)
    {
        TelaLogin->setWindowTitle(QCoreApplication::translate("TelaLogin", "Login - CliniGest", nullptr));
        labelTitle->setText(QCoreApplication::translate("TelaLogin", "Acesso ao Sistema", nullptr));
        labelUser->setText(QCoreApplication::translate("TelaLogin", "Usu\303\241rio:", nullptr));
        labelPass->setText(QCoreApplication::translate("TelaLogin", "Senha:", nullptr));
        btnLogin->setText(QCoreApplication::translate("TelaLogin", "Entrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TelaLogin: public Ui_TelaLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELALOGIN_H
