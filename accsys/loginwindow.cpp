#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "../mainwindow.h"
#include <QMessageBox>
#include "HttpClient.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow),
    httpClient(new HttpClient(this)),
    registerWindow(nullptr)
{
    ui->setupUi(this);

    connect(httpClient, &HttpClient::loginSuccess, this, [this]() {
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
        this->close();
    });
    connect(httpClient, &HttpClient::loginFailure, this, [](const QString &message) {
        QMessageBox::critical(nullptr, "Login Error", "Login failed: " + message);
    });

    connect(ui->createAccountBtn, &QPushButton::clicked, this, &LoginWindow::on_registerBtn_clicked);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginBtn_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    httpClient->loginUser(username, password);
}

void LoginWindow::on_registerBtn_clicked()
{
    RegisterWindow *registerWindow = new RegisterWindow();
    registerWindow->show();
}
