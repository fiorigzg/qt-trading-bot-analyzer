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

class SearchDialog : public QDialog {
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = nullptr);
    QString getSelectedItem() const;
    QDate getStartDate() const;
    QDate getEndDate() const;
    QString getInterval() const;
    void loadSearch(const QString &filePath, QMap<QString, QString> &dictionary);
    
private slots:
    void performSearch(const QString &text);
    void performRandomSearch();
    void itemSelected(const QModelIndex &index);
    void validateInputs();

private:
    QLineEdit *searchEdit;
    QListView *resultView;
    QStringListModel *model;
    QStringList dataList;
    QString selectedItem;
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
    QComboBox *intervalComboBox;
};

#endif // SEARCH_DIALOG_H
