#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "HttpClient.h"
#include "registerwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_loginBtn_clicked();
    void on_registerBtn_clicked();


private:
    Ui::LoginWindow *ui;
    HttpClient *httpClient;
    RegisterWindow *registerWindow;
};

#endif // LOGINWINDOW_H
