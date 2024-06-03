#include "registerwindow.h"
#include "ui_registerwindow.h"
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
    connect(httpClient, &HttpClient::registrationFailure, this, [](const QString &message) {
        QMessageBox::critical(nullptr, "Registration Error", "Registration failed: " + message);
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
    httpClient->registerUser(username, password);
}
