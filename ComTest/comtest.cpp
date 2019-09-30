#include "comtest.h"
#include "ui_comtest.h"

ComTest::ComTest(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ComTest)
{
    ui->setupUi(this);
    serial = new QSerialPort();
    //连接信号和槽
        //connect(serial, &QSerialPort::readyRead, this, &ComTest::serialPort_readyRead);

        //发送按键失能
        ui->sendButton->setEnabled(false);
        //波特率默认选择下拉第三项：9600
        ui->baudrateBox->setCurrentIndex(2);
}

ComTest::~ComTest()
{
    delete ui;
}


void ComTest::serialPort_readyRead()
{
    /*qDebug()<<"start recv"<<endl;
    //从接收缓冲区中读取数据
    QByteArray buffer = serial.readAll();
    //从界面中读取以前收到的数据
    QString recv = ui->recvTextEdit->toPlainText();
    recv += QString(buffer);
    //清空以前的显示
    ui->recvTextEdit->clear();
    //重新显示
    ui->recvTextEdit->append(recv);*/
    //qDebug()<<"read";
        //字符串或者十六进制接收
    qDebug()<<"start recv"<<endl;
        QByteArray buffer;
        buffer = serial->readAll();
        if(!buffer.isEmpty())
        {
            QString str = ui->recvTextEdit->toPlainText();
            if(ui->send_state->currentText() == "string")
            {
                str = tr(buffer);
                ui->recvTextEdit->append(str);
            }
            else
            {
               QByteArray temp = buffer.toHex().toUpper();
               str = tr(temp);
               ui->recvTextEdit->append(str);
            }
        }
        buffer.clear();
}


void ComTest::on_searchButton_clicked()
{
    ui->portNameBox->clear();
    //通过QSerialPortInfo查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->portNameBox->addItem(info.portName());
    }
}


void ComTest::on_openButton_clicked()
{
    //serial = new QSerialPort();
    serial->setPortName(ui->portNameBox->currentText());
    if(ui->openButton->text()==QString("打开串口"))
    {

        if(serial->open(QIODevice::ReadWrite))
        {
            qDebug()<<"open ok"<<endl;
            ui->openButton->setText(QString("关闭串口"));
            //设置波特率
            serial->setBaudRate(ui->baudrateBox->currentText().toInt());
            //设置数据位数
            switch(ui->dataBitsBox->currentIndex())
            {
            case 8: serial->setDataBits(QSerialPort::Data8); break;
            default: break;
            }
            //设置奇偶校验
            switch(ui->ParityBox->currentIndex())
            {
            case 0: serial->setParity(QSerialPort::NoParity); break;
            default: break;
            }
            //设置停止位
            switch(ui->stopBitsBox->currentIndex())
            {
            case 1: serial->setStopBits(QSerialPort::OneStop); break;
            case 2: serial->setStopBits(QSerialPort::TwoStop); break;
            default: break;
            }
            //设置流控制
            serial->setFlowControl(QSerialPort::NoFlowControl);
            //串口设置完成，监听数据
            //connect(serial,SIGNAL(readyRead()),this,SLOT(serialPort_readyRead()));
            //connect(serial,SIGNAL(readyRead()),this,&ComTest::serialPort_readyRead);
            connect(serial, &QSerialPort::readyRead, this, &ComTest::serialPort_readyRead);
            //下拉菜单控件失能
            ui->portNameBox->setEnabled(false);
            ui->baudrateBox->setEnabled(false);
            ui->dataBitsBox->setEnabled(false);
            ui->searchButton->setEnabled(false);
            ui->ParityBox->setEnabled(false);
            ui->stopBitsBox->setEnabled(false);
            ui->send_state->setEnabled(false);

            ui->openButton->setText(QString("关闭串口"));
            //发送按键使能
            ui->sendButton->setEnabled(true);//
        }


        else
        {
            qDebug()<<"open failed"<<endl;
            //QMessageBox::about(NULL, "提示", "无法打开串口！");
            return;
        }


    }
    else
    {
        //关闭串口
        serial->close();

        //下拉菜单控件使能
        ui->portNameBox->setEnabled(true);
        ui->baudrateBox->setEnabled(true);
        ui->dataBitsBox->setEnabled(true);
        ui->searchButton->setEnabled(true);
        ui->ParityBox->setEnabled(true);
        ui->stopBitsBox->setEnabled(true);
        ui->send_state->setEnabled(true);

        ui->openButton->setText(QString("打开串口"));
        //发送按键失能
        ui->sendButton->setEnabled(false);//
    }
}

void ComTest::on_sendButton_clicked()
{
    //获取界面上的数据并转换成utf8格式的字节流
//    QByteArray data = ui->sendTextEdit->toPlainText().toUtf8();
//    serial.write(data);
    QString str = ui->sendTextEdit->toPlainText();
        if(!str.isEmpty())
        {
            if(ui->send_state->currentText() == "string")
            {
                serial->write(str.toLatin1());
            }
            else
            {
                int num = str.toInt();
                str = str.setNum(num, 16);
                serial->write(str.toLatin1());
            }
        }
        qDebug()<<"send ok"<<endl;


}
void ComTest::on_clearButton_clicked()
{
    ui->recvTextEdit->clear();
}


void ComTest::on_pushButton_clicked()
{
    this->close();
}

