/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
    QPushButton *registerButton;
    QPushButton *backButton;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName(QString::fromUtf8("RegisterWindow"));
        RegisterWindow->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RegisterWindow->sizePolicy().hasHeightForWidth());
        RegisterWindow->setSizePolicy(sizePolicy);
        RegisterWindow->setStyleSheet(QString::fromUtf8("background-color: #2a2a3c;\n"
"font-family: Arial, sans-serif;\n"
"color: white;"));
        verticalLayout = new QVBoxLayout(RegisterWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setRowWrapPolicy(QFormLayout::WrapAllRows);
        usernameLabel = new QLabel(RegisterWindow);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, usernameLabel);

        usernameLineEdit = new QLineEdit(RegisterWindow);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));
        usernameLineEdit->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 6px;\n"
"background-color: #3E4257;\n"
"font-weight: 600;\n"
"color: white;"));

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameLineEdit);

        passwordLabel = new QLabel(RegisterWindow);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, passwordLabel);

        passwordLineEdit = new QLineEdit(RegisterWindow);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 6px;\n"
"background-color: #3E4257;\n"
"font-weight: 600;\n"
"color: white;"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordLineEdit);

        emailLabel = new QLabel(RegisterWindow);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, emailLabel);

        emailLineEdit = new QLineEdit(RegisterWindow);
        emailLineEdit->setObjectName(QString::fromUtf8("emailLineEdit"));
        emailLineEdit->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 6px;\n"
"background-color: #3E4257;\n"
"font-weight: 600;\n"
"color: white;"));

        formLayout->setWidget(2, QFormLayout::FieldRole, emailLineEdit);


        verticalLayout->addLayout(formLayout);

        registerButton = new QPushButton(RegisterWindow);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 6px;\n"
"background-color: #3E4257;\n"
"font-weight: 600;"));

        verticalLayout->addWidget(registerButton);

        backButton = new QPushButton(RegisterWindow);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 6px;\n"
"background-color: #3E4257;\n"
"font-weight: 600;"));

        verticalLayout->addWidget(backButton);


        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
        usernameLabel->setText(QCoreApplication::translate("RegisterWindow", "Username:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("RegisterWindow", "Password:", nullptr));
        emailLabel->setText(QCoreApplication::translate("RegisterWindow", "Email:", nullptr));
        registerButton->setText(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
        backButton->setText(QCoreApplication::translate("RegisterWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
