// choice_dialog.h
#ifndef CHOICE_DIALOG_H
#define CHOICE_DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>

class ChoiceDialog : public QDialog {
    Q_OBJECT
public:
    int response()
    {
        return ans;
    }

    ChoiceDialog(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Load the data");
        QVBoxLayout *layout = new QVBoxLayout(this);

        QPushButton *button1 = new QPushButton("Import .csv", this);
        QPushButton *button2 = new QPushButton("Search for stock market share (Recommended)", this);

        layout->addWidget(button1);
        layout->addWidget(button2);

        connect(button1, &QPushButton::clicked, this, &ChoiceDialog::onButton1Clicked);
        connect(button2, &QPushButton::clicked, this, &ChoiceDialog::onButton2Clicked);

        setLayout(layout);

        if (parent) {
            QRect parentGeometry = parent->geometry();
            int x = parentGeometry.center().x() - (width() / 2);
            int y = parentGeometry.center().y() - (height() / 2);
            move(x, y);
        }
}
private:
    int ans = 0;
private slots:
    void onButton1Clicked() {
        ans = 1;
        accept();
    }

    void onButton2Clicked() {
        ans = 2;
        accept();
    }
};

#endif // CHOICE_DIALOG_H
