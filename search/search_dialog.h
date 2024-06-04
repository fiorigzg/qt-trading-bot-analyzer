#ifndef SEARCH_DIALOG_H
#define SEARCH_DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QListView>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringListModel>
#include <QDateEdit>
#include <QComboBox>
#include <QDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QProgressBar>
#include <QPushButton>
#include <QMap>
#include "../graph/openglgraph.h"

class SearchDialog : public QDialog {
    Q_OBJECT

public:
    SearchDialog(QWidget *parent = nullptr, OpenGLGraph *openGLGraph = nullptr);
    QString getSelectedItem() const;
    QDate getStartDate() const;
    QDate getEndDate() const;
    QString getInterval() const;
    QString getPathToCsv() const;
    void loadSearch(const QString &filePath);
    
private slots:
    void performSearch(const QString &text);
    void performRandomSearch();
    void itemSelected(const QModelIndex &index);
    void validateInputs();
    void onDownloadButtonClicked();
    void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void onDownloadFinished();


private:
    OpenGLGraph *openGLGraph;
    QLineEdit *searchEdit;
    QListView *resultView;
    QStringListModel *model;
    QStringList dataList;
    QString selectedItem;
    QMap<QString, QString> dictionary;
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
    QComboBox *intervalComboBox;
    QProgressBar *progressBar;
    QNetworkAccessManager *networkManager;
    QNetworkReply *networkReply;
    QPushButton *downloadButton;
    QLabel *startDateLabel;
    QLabel *endDateLabel;
    QLabel *intervalLabel;
};

#endif // SEARCH_DIALOG_H
