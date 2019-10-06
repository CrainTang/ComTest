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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_ComTest
{
public:
    QWidget *centralwidget;
    QTextEdit *sendTextEdit;
    QPushButton *pushButton;
    QPushButton *openButton;
    QwtPlot *qwtPlot;
    QPushButton *searchButton;
    QPushButton *sendButton;
    QPushButton *clearButton;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *recvTextEdit;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *portNameBox;
    QLabel *label_2;
    QComboBox *baudrateBox;
    QLabel *label_5;
    QComboBox *dataBitsBox;
    QLabel *label_6;
    QComboBox *ParityBox;
    QLabel *label_7;
    QComboBox *stopBitsBox;
    QComboBox *send_state;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ComTest)
    {
        if (ComTest->objectName().isEmpty())
            ComTest->setObjectName(QString::fromUtf8("ComTest"));
        ComTest->resize(1155, 761);
        centralwidget = new QWidget(ComTest);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sendTextEdit = new QTextEdit(centralwidget);
        sendTextEdit->setObjectName(QString::fromUtf8("sendTextEdit"));
        sendTextEdit->setGeometry(QRect(20, 380, 631, 201));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(890, 330, 93, 28));
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(890, 290, 93, 28));
        qwtPlot = new QwtPlot(centralwidget);
        qwtPlot->setObjectName(QString::fromUtf8("qwtPlot"));
        qwtPlot->setGeometry(QRect(700, 370, 400, 200));
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(1010, 290, 93, 28));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(330, 600, 321, 28));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(20, 600, 301, 28));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 30, 72, 15));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 360, 72, 15));
        recvTextEdit = new QTextEdit(centralwidget);
        recvTextEdit->setObjectName(QString::fromUtf8("recvTextEdit"));
        recvTextEdit->setGeometry(QRect(20, 50, 631, 301));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(900, 34, 164, 241));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        portNameBox = new QComboBox(layoutWidget);
        portNameBox->setObjectName(QString::fromUtf8("portNameBox"));

        gridLayout->addWidget(portNameBox, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        baudrateBox = new QComboBox(layoutWidget);
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->setObjectName(QString::fromUtf8("baudrateBox"));

        gridLayout->addWidget(baudrateBox, 1, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        dataBitsBox = new QComboBox(layoutWidget);
        dataBitsBox->addItem(QString());
        dataBitsBox->setObjectName(QString::fromUtf8("dataBitsBox"));

        gridLayout->addWidget(dataBitsBox, 2, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        ParityBox = new QComboBox(layoutWidget);
        ParityBox->addItem(QString());
        ParityBox->setObjectName(QString::fromUtf8("ParityBox"));

        gridLayout->addWidget(ParityBox, 3, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        stopBitsBox = new QComboBox(layoutWidget);
        stopBitsBox->addItem(QString());
        stopBitsBox->addItem(QString());
        stopBitsBox->setObjectName(QString::fromUtf8("stopBitsBox"));

        gridLayout->addWidget(stopBitsBox, 4, 1, 1, 1);

        send_state = new QComboBox(centralwidget);
        send_state->addItem(QString());
        send_state->addItem(QString());
        send_state->setObjectName(QString::fromUtf8("send_state"));
        send_state->setGeometry(QRect(780, 290, 87, 22));
        ComTest->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ComTest);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1155, 26));
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
        pushButton->setText(QCoreApplication::translate("ComTest", "\351\200\200\345\207\272", nullptr));
        openButton->setText(QCoreApplication::translate("ComTest", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        searchButton->setText(QCoreApplication::translate("ComTest", "\346\243\200\346\265\213\344\270\262\345\217\243", nullptr));
        sendButton->setText(QCoreApplication::translate("ComTest", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        clearButton->setText(QCoreApplication::translate("ComTest", "\346\270\205\347\251\272\346\216\245\346\224\266", nullptr));
        label_3->setText(QCoreApplication::translate("ComTest", "\346\216\245\346\224\266\347\252\227\345\217\243", nullptr));
        label_4->setText(QCoreApplication::translate("ComTest", "\345\217\221\351\200\201\347\252\227\345\217\243", nullptr));
        label->setText(QCoreApplication::translate("ComTest", "\344\270\262\345\217\243\345\217\267 \357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("ComTest", "\346\263\242\347\211\271\347\216\207 \357\274\232", nullptr));
        baudrateBox->setItemText(0, QCoreApplication::translate("ComTest", "9600", nullptr));
        baudrateBox->setItemText(1, QCoreApplication::translate("ComTest", "19200", nullptr));
        baudrateBox->setItemText(2, QCoreApplication::translate("ComTest", "115200", nullptr));

        label_5->setText(QCoreApplication::translate("ComTest", "\346\225\260\346\215\256\344\275\215 \357\274\232", nullptr));
        dataBitsBox->setItemText(0, QCoreApplication::translate("ComTest", "8", nullptr));

        label_6->setText(QCoreApplication::translate("ComTest", "\346\240\241\351\252\214\344\275\215 \357\274\232", nullptr));
        ParityBox->setItemText(0, QCoreApplication::translate("ComTest", "0", nullptr));

        label_7->setText(QCoreApplication::translate("ComTest", "\345\201\234\346\255\242\344\275\215 \357\274\232", nullptr));
        stopBitsBox->setItemText(0, QCoreApplication::translate("ComTest", "1", nullptr));
        stopBitsBox->setItemText(1, QCoreApplication::translate("ComTest", "2", nullptr));

        send_state->setItemText(0, QCoreApplication::translate("ComTest", "string", nullptr));
        send_state->setItemText(1, QCoreApplication::translate("ComTest", "hex", nullptr));

    } // retranslateUi

};

namespace Ui {
    class ComTest: public Ui_ComTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMTEST_H
