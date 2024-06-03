#include "loginwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow loginWindow;
    loginWindow.setWindowTitle("Trading Bot Analyzer");
    loginWindow.show();
    return a.exec();
}
