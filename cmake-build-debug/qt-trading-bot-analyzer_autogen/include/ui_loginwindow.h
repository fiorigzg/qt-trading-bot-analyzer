/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *passwordLineEdit;
    QCheckBox *rememberMeCheckBox;
    QPushButton *loginBtn;
    QLineEdit *usernameLineEdit;
    QPushButton *createAccountBtn;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLabel *titleLabel;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(400, 400);
        LoginWindow->setMinimumSize(QSize(400, 400));
        LoginWindow->setStyleSheet(QString::fromUtf8("background-color: #2a2a3c;\n"
"font-family: Arial, sans-serif;\n"
"color: white;"));
        actionExit = new QAction(LoginWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(9);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(18, -1, -1, 18);
        passwordLineEdit = new QLineEdit(centralwidget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setMinimumSize(QSize(200, 30));
        passwordLineEdit->setFocusPolicy(Qt::ClickFocus);
        passwordLineEdit->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 6px;\n"
"background-color: #3E4257;\n"
"font-weight: 600;\n"
"color: white;"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordLineEdit, 2, 1, 1, 1);

        rememberMeCheckBox = new QCheckBox(centralwidget);
        rememberMeCheckBox->setObjectName(QString::fromUtf8("rememberMeCheckBox"));
        rememberMeCheckBox->setStyleSheet(QString::fromUtf8("color: white;"));

        gridLayout->addWidget(rememberMeCheckBox, 3, 1, 1, 1);

        loginBtn = new QPushButton(centralwidget);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setMinimumSize(QSize(0, 40));
        loginBtn->setCursor(QCursor(Qt::PointingHandCursor));
        loginBtn->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 6px;\n"
"background-color: #3E4257;\n"
"font-weight: 600;"));

        gridLayout->addWidget(loginBtn, 4, 0, 1, 2);

        usernameLineEdit = new QLineEdit(centralwidget);
        usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));
        usernameLineEdit->setMinimumSize(QSize(200, 30));
        usernameLineEdit->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 6px;\n"
"background-color: #3E4257;\n"
"font-weight: 600;\n"
"color: white;"));

        gridLayout->addWidget(usernameLineEdit, 1, 1, 1, 1);

        createAccountBtn = new QPushButton(centralwidget);
        createAccountBtn->setObjectName(QString::fromUtf8("createAccountBtn"));
        createAccountBtn->setMinimumSize(QSize(0, 40));
        createAccountBtn->setCursor(QCursor(Qt::PointingHandCursor));
        createAccountBtn->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 6px;\n"
"background-color: #3E4257;\n"
"font-weight: 600;"));

        gridLayout->addWidget(createAccountBtn, 5, 0, 1, 2);

        usernameLabel = new QLabel(centralwidget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"font-weight: bold;\n"
"color: white;"));

        gridLayout->addWidget(usernameLabel, 1, 0, 1, 1);

        passwordLabel = new QLabel(centralwidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"font-weight: bold;\n"
"color: white;"));

        gridLayout->addWidget(passwordLabel, 2, 0, 1, 1);

        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 24px;\n"
"font-weight: bold;\n"
"color: white;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(titleLabel, 0, 0, 1, 2);

        LoginWindow->setCentralWidget(centralwidget);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        actionExit->setText(QCoreApplication::translate("LoginWindow", "Exit", nullptr));
        rememberMeCheckBox->setText(QCoreApplication::translate("LoginWindow", "Remember Me", nullptr));
        loginBtn->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        createAccountBtn->setText(QCoreApplication::translate("LoginWindow", "Create an account", nullptr));
        usernameLabel->setText(QCoreApplication::translate("LoginWindow", "Username:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("LoginWindow", "Password:", nullptr));
        titleLabel->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
