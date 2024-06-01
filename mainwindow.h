#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QBrush>
#include "openglgraph.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_importFileBtn_clicked();
    void on_runBtn_clicked();

private slots:
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    OpenGLGraph *openGLGraph;
};

#endif // MAINWINDOW_H
