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
#include <QMessageBox>
#include <QDate>
#include <QPushButton>
#include <QLabel> 

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

    // Add date and interval selection
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
    intervalComboBox->addItem("1 week", "1wk");
    intervalComboBox->addItem("1 month", "1mo");

    layout->addWidget(new QLabel("start date:"));
    layout->addWidget(startDateEdit);
    layout->addWidget(new QLabel("end date:"));
    layout->addWidget(endDateEdit);
    layout->addWidget(new QLabel("candle interval:"));
    layout->addWidget(intervalComboBox);

    // Add the download button
    downloadButton = new QPushButton("Download", this);
    downloadButton->setStyleSheet("background-color: green; color: white;");
    downloadButton->setEnabled(false);
    layout->addWidget(downloadButton);

    connect(startDateEdit, &QDateEdit::dateChanged, this, &SearchDialog::validateInputs);
    connect(endDateEdit, &QDateEdit::dateChanged, this, &SearchDialog::validateInputs);
    connect(intervalComboBox, &QComboBox::currentIndexChanged, this, &SearchDialog::validateInputs);
    connect(downloadButton, &QPushButton::clicked, this, &QDialog::accept);
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
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Couldn't open file:" << filePath;
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

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

    downloadButton->setEnabled(isValid);
}
