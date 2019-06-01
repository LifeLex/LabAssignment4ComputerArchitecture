/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *number1;
    QPlainTextEdit *number1Hex;
    QPlainTextEdit *number2;
    QPlainTextEdit *number2Hex;
    QPushButton *adding;
    QPushButton *multiplying;
    QPushButton *dividing;
    QPlainTextEdit *result;
    QPlainTextEdit *resultHex;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(646, 358);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        number1 = new QPlainTextEdit(centralWidget);
        number1->setObjectName(QString::fromUtf8("number1"));
        number1->setGeometry(QRect(20, 20, 191, 31));
        number1Hex = new QPlainTextEdit(centralWidget);
        number1Hex->setObjectName(QString::fromUtf8("number1Hex"));
        number1Hex->setGeometry(QRect(20, 60, 191, 31));
        number2 = new QPlainTextEdit(centralWidget);
        number2->setObjectName(QString::fromUtf8("number2"));
        number2->setGeometry(QRect(370, 20, 221, 31));
        number2Hex = new QPlainTextEdit(centralWidget);
        number2Hex->setObjectName(QString::fromUtf8("number2Hex"));
        number2Hex->setGeometry(QRect(370, 60, 221, 31));
        adding = new QPushButton(centralWidget);
        adding->setObjectName(QString::fromUtf8("adding"));
        adding->setGeometry(QRect(20, 100, 121, 31));
        multiplying = new QPushButton(centralWidget);
        multiplying->setObjectName(QString::fromUtf8("multiplying"));
        multiplying->setGeometry(QRect(240, 100, 111, 31));
        dividing = new QPushButton(centralWidget);
        dividing->setObjectName(QString::fromUtf8("dividing"));
        dividing->setGeometry(QRect(460, 100, 131, 31));
        result = new QPlainTextEdit(centralWidget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(30, 160, 151, 31));
        resultHex = new QPlainTextEdit(centralWidget);
        resultHex->setObjectName(QString::fromUtf8("resultHex"));
        resultHex->setGeometry(QRect(30, 200, 151, 31));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(230, 150, 371, 141));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 646, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        adding->setText(QApplication::translate("MainWindow", "Adding", nullptr));
        multiplying->setText(QApplication::translate("MainWindow", "Multiplying", nullptr));
        dividing->setText(QApplication::translate("MainWindow", "Dividing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
