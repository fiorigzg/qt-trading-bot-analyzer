#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "openglgraph.h"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto *openGLBox = findChild<QWidget*>("openGLBox");
    QVBoxLayout *openGLLayout = new QVBoxLayout(openGLBox);
    openGLGraph = new OpenGLGraph(openGLBox);
    openGLLayout->addWidget(openGLGraph);
    openGLBox->setLayout(openGLLayout);
    openGLGraph->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_importFileBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open CSV File"), "", tr("CSV Files (*.csv);;All Files (*)"));
    if (fileName.isEmpty()) {
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, tr("File Error"), tr("Unable to open file."));
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        // Обрабатываем строку CSV здесь

        qDebug() << line;
    }
    file.close();
    QMessageBox::information(this, tr("File Imported"), tr("CSV file imported successfully."));
}

void MainWindow::on_runBtn_clicked()
{
    openGLGraph->switchTimer();
}
