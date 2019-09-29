/********************************************************************************
** Form generated from reading UI file 'comtest.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMTEST_H
#define UI_COMTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComTest
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ComTest)
    {
        if (ComTest->objectName().isEmpty())
            ComTest->setObjectName(QString::fromUtf8("ComTest"));
        ComTest->resize(800, 600);
        centralwidget = new QWidget(ComTest);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 20, 631, 311));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 350, 631, 201));
        ComTest->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ComTest);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        ComTest->setMenuBar(menubar);
        statusbar = new QStatusBar(ComTest);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ComTest->setStatusBar(statusbar);

        retranslateUi(ComTest);

        QMetaObject::connectSlotsByName(ComTest);
    } // setupUi

    void retranslateUi(QMainWindow *ComTest)
    {
        ComTest->setWindowTitle(QCoreApplication::translate("ComTest", "ComTest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComTest: public Ui_ComTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMTEST_H
