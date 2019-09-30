#ifndef COMTEST_H
#define COMTEST_H

#include <QMainWindow>//
#include "qDebug.h"						  // 调试输出用
#include <QSerialPort>         // 提供访问串口的功能
#include <QSerialPortInfo>     // 提供系统中存在的串口的信息
#include <QMetaType>
QT_BEGIN_NAMESPACE
namespace Ui { class ComTest; }//
QT_END_NAMESPACE

class ComTest : public QMainWindow
{
    Q_OBJECT

public:
    ComTest(QWidget *parent = nullptr);
    ~ComTest();

private slots:

    void serialPort_readyRead();

    void on_pushButton_clicked();

    void on_searchButton_clicked();

    void on_openButton_clicked();

    void on_sendButton_clicked();

    void on_clearButton_clicked();


private:
    Ui::ComTest *ui;
    QSerialPort *serial;

};
#endif // COMTEST_H
