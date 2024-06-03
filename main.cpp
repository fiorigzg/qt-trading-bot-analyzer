#include "accsys/loginwindow.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // LoginWindow loginWindow;
    // loginWindow.setWindowTitle("Trading Bot Analyzer");
    // loginWindow.show();
    MainWindow w;
    w.setWindowTitle("Trading Bot Analyzer");
    w.show();
    return a.exec();
}
