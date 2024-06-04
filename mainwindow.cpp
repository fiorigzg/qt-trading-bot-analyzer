#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "search/choice_dialog.h"
#include "search/search_dialog.h"
#include "graph/openglgraph.h"
#include <QProgressBar>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qnetworkreply.h>
#include <QFileDialog>
#include <QString>
#include <qstringlist.h>
#include <QFile>
#include <QDate>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

QString stpBck(const QString &s) {
    int lastSlashIndex = s.lastIndexOf('/', s.length() - 2); // Find the last slash, ignoring the trailing slash
    if (lastSlashIndex != -1) {
        return s.left(lastSlashIndex + 1); // Include the slash at the end of the result
    }
    return s; // Return the original string if no slash
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto *portfolio = findChild<QLabel*>("portfolio");

    auto *openGLBox = findChild<QWidget*>("openGLBox");
    QVBoxLayout *openGLLayout = new QVBoxLayout(openGLBox);
    openGLGraph = new OpenGLGraph(openGLBox, portfolio);
    openGLLayout->addWidget(openGLGraph);
    openGLBox->setLayout(openGLLayout);
    openGLGraph->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QDir cacheDir(stpBck(QCoreApplication::applicationDirPath()) + "cache/");
    QFileInfoList fileList = cacheDir.entryInfoList(QDir::Files);
    for (const QFileInfo &fileInfo : fileList) {        
        PathToCsv = fileInfo.absoluteFilePath();
    }
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
    ChoiceDialog selector = new ChoiceDialog(this);
    selector.exec();
    if (selector.response() == 1)
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
    else if (selector.response() == 2)
    {
        SearchDialog stockSearch = SearchDialog(this);
        QString filePath = "search/ticker.json";
        stockSearch.loadSearch(filePath);
        stockSearch.exec();
        PathToCsv = stockSearch.getPathToCsv();
    }
}

void MainWindow::on_runBtn_clicked()
{
    qWarning() << PathToCsv; // путь к файлу для построения графика
    // в папке cache всегда лежит один цсв файл, при скачке он удаляется и
    // скачивается новый, его пушьте прям на гитхаб он нихуя не весит
    // Path to Csv тож обновляеостся после каждой скачки
    openGLGraph->switchTimer();
}
