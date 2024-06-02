#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "HttpClient.h"

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
    void on_registerLabel_linkActivated(const QString &link);

private:
    Ui::LoginWindow *ui;
    HttpClient *httpClient;
};

#endif // LOGINWINDOW_H
