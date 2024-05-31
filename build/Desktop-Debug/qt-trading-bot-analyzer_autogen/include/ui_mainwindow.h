/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *mainBox;
    QGridLayout *gridLayout_2;
    QWidget *menuBox;
    QGridLayout *gridLayout_3;
    QPushButton *chooseBtn;
    QPushButton *importFileBtn;
    QFrame *resultBox;
    QHBoxLayout *horizontalLayout;
    QLabel *result;
    QLabel *currency;
    QWidget *ordersBox;
    QGridLayout *gridLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *runBtn;
    QWidget *openGLBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(914, 695);
        MainWindow->setMinimumSize(QSize(500, 400));
        MainWindow->setStyleSheet(QString::fromUtf8("    background-color: #2a2a3c;\n"
"    font-family: Arial, sans-serif;\n"
"    color: white;"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        centralwidget->setMaximumSize(QSize(16777215, 16777215));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(9);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setContentsMargins(18, -1, -1, 18);
        mainBox = new QWidget(centralwidget);
        mainBox->setObjectName("mainBox");
        gridLayout_2 = new QGridLayout(mainBox);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        menuBox = new QWidget(mainBox);
        menuBox->setObjectName("menuBox");
        menuBox->setMinimumSize(QSize(250, 100));
        menuBox->setMaximumSize(QSize(250, 16777215));
        gridLayout_3 = new QGridLayout(menuBox);
        gridLayout_3->setSpacing(9);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(9, 0, 9, 0);
        chooseBtn = new QPushButton(menuBox);
        chooseBtn->setObjectName("chooseBtn");
        chooseBtn->setMinimumSize(QSize(0, 40));
        chooseBtn->setCursor(QCursor(Qt::PointingHandCursor));
        chooseBtn->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 6px;\n"
"background-color: #3E4257;\n"
"font-weight: 600;"));

        gridLayout_3->addWidget(chooseBtn, 1, 0, 1, 1);

        importFileBtn = new QPushButton(menuBox);
        importFileBtn->setObjectName("importFileBtn");
        importFileBtn->setMinimumSize(QSize(0, 40));
        importFileBtn->setCursor(QCursor(Qt::PointingHandCursor));
        importFileBtn->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 6px;\n"
"background-color: #3E4257;\n"
"font-weight: 600;"));

        gridLayout_3->addWidget(importFileBtn, 0, 0, 1, 1);

        resultBox = new QFrame(menuBox);
        resultBox->setObjectName("resultBox");
        resultBox->setMinimumSize(QSize(0, 50));
        resultBox->setMaximumSize(QSize(16777215, 50));
        resultBox->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 6px;\n"
"background-color: #1D2033;\n"
"font-weight: 600;"));
        resultBox->setFrameShape(QFrame::StyledPanel);
        resultBox->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(resultBox);
        horizontalLayout->setObjectName("horizontalLayout");
        result = new QLabel(resultBox);
        result->setObjectName("result");
        result->setMaximumSize(QSize(300, 16777215));
        result->setStyleSheet(QString::fromUtf8("color: #E75151;\n"
""));

        horizontalLayout->addWidget(result, 0, Qt::AlignRight);

        currency = new QLabel(resultBox);
        currency->setObjectName("currency");
        currency->setMaximumSize(QSize(90, 16777215));

        horizontalLayout->addWidget(currency);


        gridLayout_3->addWidget(resultBox, 3, 0, 1, 1);

        ordersBox = new QWidget(menuBox);
        ordersBox->setObjectName("ordersBox");
        ordersBox->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 6px;\n"
"background-color: #1D2033;\n"
"font-weight: 600;"));
        gridLayout_5 = new QGridLayout(ordersBox);
        gridLayout_5->setObjectName("gridLayout_5");
        scrollArea = new QScrollArea(ordersBox);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 214, 426));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_5->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout_3->addWidget(ordersBox, 4, 0, 1, 1);

        runBtn = new QPushButton(menuBox);
        runBtn->setObjectName("runBtn");
        runBtn->setMinimumSize(QSize(0, 40));
        runBtn->setCursor(QCursor(Qt::PointingHandCursor));
        runBtn->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 6px;\n"
"background-color: #3E4257;\n"
"font-weight: 600;"));

        gridLayout_3->addWidget(runBtn, 2, 0, 1, 1);


        gridLayout_2->addWidget(menuBox, 0, 1, 1, 1);

        openGLBox = new QWidget(mainBox);
        openGLBox->setObjectName("openGLBox");
        openGLBox->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-radius: 6px;\n"
"background-color: #1D2033;\n"
"font-weight: 600;"));

        gridLayout_2->addWidget(openGLBox, 0, 0, 1, 1);


        gridLayout->addWidget(mainBox, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        chooseBtn->setText(QCoreApplication::translate("MainWindow", "Choose", nullptr));
        importFileBtn->setText(QCoreApplication::translate("MainWindow", "Import file", nullptr));
        result->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        currency->setText(QCoreApplication::translate("MainWindow", "$", nullptr));
        runBtn->setText(QCoreApplication::translate("MainWindow", "Run / pause", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
