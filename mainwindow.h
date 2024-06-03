#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QBrush>
#include <QProgressBar>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qnetworkreply.h>
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
    void handleSelection(const QString &text);

public slots:
    void on_importFileBtn_clicked();
    void on_runBtn_clicked();

private slots:
    void on_actionExit_triggered();
    void onDownloadButtonClicked(const QString& ticker);
    void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void onDownloadFinished();

private:
    Ui::MainWindow *ui;
    OpenGLGraph *openGLGraph;
    void loadJsonFile(const QString &filePath, QMap<QString, QString> &dictionary, QStringList &list);
    QMap<QString, QString> dictionary;
    QStringList dataList;
    QProgressBar *progressBar;
    QNetworkAccessManager *networkManager;
    QNetworkReply *networkReply;
};

#endif // MAINWINDOW_H
