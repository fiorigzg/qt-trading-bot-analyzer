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
        button1->setStyleSheet("border-style: solid; border-radius: 6px; background-color: #3E4257; font-weight: 600;");
        button1->setFixedHeight(40);
        button1->setCursor(Qt::PointingHandCursor);
        QPushButton *button2 = new QPushButton("Search for stock market share (Recommended)", this);
        button2->setStyleSheet("border-style: solid; border-radius: 6px; background-color: #3E4257; font-weight: 600; margin-top: 3px;");
        button2->setFixedHeight(40);
        button2->setMinimumWidth(400);
        button2->setCursor(Qt::PointingHandCursor);

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
