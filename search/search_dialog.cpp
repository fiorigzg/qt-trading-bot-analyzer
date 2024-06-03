#include "search_dialog.h"
#include <QVBoxLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringListModel>
#include <QDebug>
#include <QTextStream>
#include <algorithm>
#include <random>
#include <chrono>
#include <QCoreApplication>
#include <QMessageBox>
#include <QDate>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

QString filename(const QString &path) {
    int lastSlashIndex = -1;
    for (int i = 0; i < path.length(); ++i) {
        if (path[i] == '/' || path[i] == '\\') {
            lastSlashIndex = i;
        }
    }
    QString fileName = path.mid(lastSlashIndex);
    return fileName;
}

QString toTimestamp(QDateEdit *dateEdit) {
    // Get the QDate from the QDateEdit
    QDate date = dateEdit->date();

    // Convert QDate to QDateTime (at the start of the day)
    QDateTime dateTime(date, QTime(0, 0));

    // Get the Unix timestamp from QDateTime
    qint64 unixTimestamp = dateTime.toSecsSinceEpoch();

    // Convert the Unix timestamp to QString
    QString timestampStr = QString::number(unixTimestamp);

    return timestampStr;
}

QString SearchDialog::getSelectedItem() const
{
    return this->selectedItem;
}

SearchDialog::SearchDialog(QWidget *parent)
    : QDialog(parent), selectedItem("") {
    setWindowTitle("Search");

    QVBoxLayout *layout = new QVBoxLayout(this);

    searchEdit = new QLineEdit(this);
    resultView = new QListView(this);
    model = new QStringListModel(this);

    resultView->setModel(model);

    layout->addWidget(searchEdit);
    layout->addWidget(resultView);

    connect(searchEdit, &QLineEdit::textChanged, this, &SearchDialog::performSearch);
    connect(resultView, &QListView::clicked, this, &SearchDialog::itemSelected);

    startDateEdit = new QDateEdit(QDate::currentDate().addYears(-1), this);
    startDateEdit->setCalendarPopup(true);
    startDateEdit->setMinimumDate(QDate(1990, 1, 1));
    startDateEdit->setMaximumDate(QDate::currentDate());

    endDateEdit = new QDateEdit(QDate::currentDate(), this);
    endDateEdit->setCalendarPopup(true);
    endDateEdit->setMinimumDate(QDate(1990, 1, 1));
    endDateEdit->setMaximumDate(QDate::currentDate());

    intervalComboBox = new QComboBox(this);
    intervalComboBox->addItem("1 day", "1d");
    intervalComboBox->addItem("1 week", "1w");
    intervalComboBox->addItem("1 month", "1m");

    layout->addWidget(new QLabel("start date:"));
    layout->addWidget(startDateEdit);
    layout->addWidget(new QLabel("end date:"));
    layout->addWidget(endDateEdit);
    layout->addWidget(new QLabel("candle interval:"));
    layout->addWidget(intervalComboBox);

    connect(startDateEdit, &QDateEdit::dateChanged, this, &SearchDialog::validateInputs);
    connect(endDateEdit, &QDateEdit::dateChanged, this, &SearchDialog::validateInputs);
    connect(intervalComboBox, &QComboBox::currentIndexChanged, this, &SearchDialog::validateInputs);
    setLayout(layout);

    if (parent) {
        QRect parentGeometry = parent->geometry();
        int x = parentGeometry.center().x() - (width() / 2);
        int y = parentGeometry.center().y() - (height() / 2);
        move(x, y);
    }

    performRandomSearch();
}

void SearchDialog::loadSearch(const QString &filePath, QMap<QString, QString> &dictionary) {
    QFile file1(".." + filePath);
    QByteArray jsonData;
    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text)) {
        file1.close();
        QFile file2(QCoreApplication::applicationDirPath() + filename(filePath));
        if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
            file2.close();
            QFile file3("/ticker.json");
            if (!file3.open(QIODevice::ReadOnly | QIODevice::Text)) {
                qWarning("There's an error with loading search system");
                return;
            } else {
                jsonData = file3.readAll();
            }
        } else {
            jsonData = file2.readAll();
        }
    } else {
        jsonData = file1.readAll();
    }

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (doc.isNull() || !doc.isObject()) {
        qWarning() << "Invalid JSON file format";
        return;
    }

    QJsonObject jsonObj = doc.object();
    for (auto it = jsonObj.begin(); it != jsonObj.end(); ++it) {
        dataList.append(it.key());
        dictionary.insert(it.key(),it.value().toString());
    }
    performRandomSearch();
}

void shuffleQStringList(QStringList &list) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(list.begin(), list.end(), std::default_random_engine(seed));
}

void SearchDialog::performRandomSearch() {
    shuffleQStringList(dataList);
    model->setStringList(dataList);
}

void SearchDialog::performSearch(const QString &text) {
    QStringList filteredList;
    for (const QString &item : dataList) {
        if (item.startsWith(text, Qt::CaseInsensitive)) {
            filteredList << item;
        }
    }
    model->setStringList(filteredList);
}

void SearchDialog::itemSelected(const QModelIndex &index) {
    selectedItem = model->data(index, Qt::DisplayRole).toString();
    accept();
}

QDate SearchDialog::getStartDate() const {
    return startDateEdit->date();
}

QDate SearchDialog::getEndDate() const {
    return endDateEdit->date();
}

QString SearchDialog::getInterval() const {
    return intervalComboBox->currentData().toString();
}

void SearchDialog::validateInputs() {
    bool isValid = !selectedItem.isEmpty() &&
                   startDateEdit->date() < endDateEdit->date() &&
                   !intervalComboBox->currentText().isEmpty();
}



// void MainWindow::onDownloadButtonClicked() {
//     // QString url = constructYahooFinanceUrl(ticker, startDate, endDate, interval);
//     // QNetworkRequest request{QUrl(url)}; 

//     // networkReply = networkManager->get(request);

//     // // Connect signals for progress and completion
//     // connect(networkReply, &QNetworkReply::downloadProgress, this, &MainWindow::onDownloadProgress);
//     // connect(networkReply, &QNetworkReply::finished, this, &MainWindow::onDownloadFinished);
// }

// void MainWindow::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal)
// {
//     if (bytesTotal > 0) {
//         progressBar->setValue(static_cast<int>((bytesReceived * 100) / bytesTotal));
//     }
// }

// void MainWindow::onDownloadFinished()
// {
//     if (networkReply->error() == QNetworkReply::NoError) {
//         QByteArray data = networkReply->readAll();

//         // Save the downloaded data to a file
//         QString fileName = QFileDialog::getSaveFileName(this, tr("Save CSV File"), "", tr("CSV Files (*.csv);;All Files (*)"));
//         if (!fileName.isEmpty()) {
//             QFile file(fileName);
//             if (file.open(QIODevice::WriteOnly)) {
//                 file.write(data);
//                 file.close();
//                 QMessageBox::information(this, tr("Download Complete"), tr("The file has been downloaded successfully."));
//             } else {
//                 QMessageBox::warning(this, tr("File Error"), tr("Unable to save the file."));
//             }
//         }
//     } else {
//         QMessageBox::warning(this, tr("Download Error"), tr("Failed to download the file."));
//     }

//     networkReply->deleteLater();
//     networkReply = nullptr;
//     progressBar->setValue(0);
// }
