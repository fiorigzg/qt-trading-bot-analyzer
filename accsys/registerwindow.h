#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include "HttpClient.h"

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void on_registerButton_clicked();

private:
    Ui::RegisterWindow *ui;
    HttpClient *httpClient;
};

#endif // REGISTERWINDOW_H
