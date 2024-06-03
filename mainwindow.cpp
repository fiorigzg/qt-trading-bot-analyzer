#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "choice_dialog.h"
#include "search_dialog.h"
#include "graph/openglgraph.h"

#include <QProgressBar>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qnetworkreply.h>
#include <QFileDialog>
#include <QString>
#include <qstringlist.h>
#include <QFile>
#include <QMap>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

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
        QString filePath = "../ticker.json";
        stockSearch.loadSearch(filePath, dictionary);
        stockSearch.exec();
    }
}

void MainWindow::on_runBtn_clicked()
{
    openGLGraph->switchTimer();
}

void MainWindow::onDownloadButtonClicked(const QString& ticker) {
    // QString url = constructYahooFinanceUrl(ticker, startDate, endDate, interval);
    // QNetworkRequest request{QUrl(url)}; 

    // networkReply = networkManager->get(request);

    // // Connect signals for progress and completion
    // connect(networkReply, &QNetworkReply::downloadProgress, this, &MainWindow::onDownloadProgress);
    // connect(networkReply, &QNetworkReply::finished, this, &MainWindow::onDownloadFinished);
}

void MainWindow::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    if (bytesTotal > 0) {
        progressBar->setValue(static_cast<int>((bytesReceived * 100) / bytesTotal));
    }
}

void MainWindow::onDownloadFinished()
{
    if (networkReply->error() == QNetworkReply::NoError) {
        QByteArray data = networkReply->readAll();

        // Save the downloaded data to a file
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save CSV File"), "", tr("CSV Files (*.csv);;All Files (*)"));
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly)) {
                file.write(data);
                file.close();
                QMessageBox::information(this, tr("Download Complete"), tr("The file has been downloaded successfully."));
            } else {
                QMessageBox::warning(this, tr("File Error"), tr("Unable to save the file."));
            }
        }
    } else {
        QMessageBox::warning(this, tr("Download Error"), tr("Failed to download the file."));
    }

    networkReply->deleteLater();
    networkReply = nullptr;
    progressBar->setValue(0);
}
