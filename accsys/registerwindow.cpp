#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "HttpClient.h"
#include <QMessageBox>

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow),
    httpClient(new HttpClient(this))
{
    ui->setupUi(this);

    connect(httpClient, &HttpClient::registrationSuccess, this, [this]() {
        QMessageBox::information(this, "Registration", "User registered successfully.");
        this->close();
    });
    connect(httpClient, &HttpClient::registrationFailure, this, [this](const QString &message) {
        QMessageBox::information(this, "Registration", "User registered successfully.");
        this->close();
    });
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
    delete httpClient;
}

void RegisterWindow::on_registerButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString email = ui->emailLineEdit->text();
    httpClient->registerUser(username, password, email);
}

void RegisterWindow::on_backButton_clicked()
{
    close();
}
