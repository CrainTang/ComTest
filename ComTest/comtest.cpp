#include "comtest.h"
#include "ui_comtest.h"
ComTest::ComTest(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ComTest)
{
    ui->setupUi(this);
    this->setWindowTitle("简易频谱仪");
    ui->sendButton->setEnabled(false);//发送按键失能
    ui->baudrateBox->setCurrentIndex(0);//波特率默认选择下拉第一项：9600
    //Plot();

}

ComTest::~ComTest()
{
    delete ui;
}


void ComTest::serialPort_readyRead()
{
    qDebug()<<"start recv"<<endl;
    QByteArray buffer;
    buffer = serial->readAll();
    qDebug()<<buffer<<endl;
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


//画图
void ComTest::Plot()
{ 

    ui->qwtPlot->setAxisScale(QwtPlot::yLeft,0,100,5);
    ui->qwtPlot->setAxisScale(QwtPlot::xBottom,-5000,5000,1000);
    ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,"幅度");
    ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,"频率(kHz)");

    QVector<QPointF> vector;
    for(int i =-512;i<512;i++)
    {
        QPointF point;
        point.setX(i*10000/1024);
        double y = list1[i+512].toDouble();
        qDebug()<<y<<endl;
        //i = i + 10000000/1024;
        //int y = 20*sin(i*M_PI/10) + 50;
        point.setY(y);
        vector.append(point);
    }

    //构造曲线数据
    QwtPointSeriesData* series = new QwtPointSeriesData(vector);


    QwtPlotCurve* curve1 = new QwtPlotCurve("Curve 1");
    //设置数据
    curve1->setData(series);
    //把曲线附加到qwtPlot上
    curve1->attach(ui->qwtPlot);
    //设置画笔
    curve1->setPen(QColor(0,0,255),2,Qt::SolidLine);
    //加入网格
    QwtPlotGrid* grid = new QwtPlotGrid();
    grid->setPen(QColor(222,222,222),1);
    grid->attach(ui->qwtPlot);
    ui->qwtPlot->replot();
    ui->qwtPlot->show();
    //删除所画的图形
    //curve1->detach();
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
    QString portName = ui->portNameBox->currentText();
    if(ui->openButton->text()==QString("打开串口"))
    {
        serial = new Win_QextSerialPort(portName,QextSerialBase::EventDriven);
        if(serial->open(QIODevice::ReadWrite))
        {
            qDebug()<<"open ok"<<endl;
            ui->openButton->setText(QString("关闭串口"));
            //设置波特率
            switch (ui->baudrateBox->currentIndex())
            {
                case 0:serial->setBaudRate(BAUD9600);break;
                case 1:serial->setBaudRate(BAUD19200);break;
                case 2:serial->setBaudRate(BAUD115200);break;
                default: break;
            }
            //设置数据位数
            switch(ui->dataBitsBox->currentIndex())
            {
                case 0: serial->setDataBits(DATA_8); break;
                default: break;
            }
            //设置奇偶校验
            switch(ui->ParityBox->currentIndex())
            {
                case 0: serial->setParity(PAR_NONE); break;
                default: break;
            }
            //设置停止位
            switch(ui->stopBitsBox->currentIndex())
            {
                case 1: serial->setStopBits(STOP_1); break;
                case 2: serial->setStopBits(STOP_2); break;
                default: break;
            }
            //设置流控制
            serial->setFlowControl(FLOW_OFF);

            //串口设置完成，监听数据
            connect(serial,SIGNAL(readyRead()),this,SLOT(serialPort_readyRead()));

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
            return;
        }
    }
    else
    {       
        serial->close();//关闭串口

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
        ui->sendButton->setEnabled(false);
    }
}

void ComTest::on_sendButton_clicked()
{

    QString str = ui->sendTextEdit->toPlainText();
    //QByteArray str11 = str.toLatin1();
    //qDebug()<<str.toLatin1()<<endl;
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
    qDebug()<<"send ok:"<<str<<endl;


}
void ComTest::on_clearButton_clicked()
{
    ui->recvTextEdit->clear();
}


void ComTest::on_pushButton_clicked()
{
    this->close();
}


void ComTest::on_pushButton_2_clicked()
{
    QString strbuf = ui->recvTextEdit->toPlainText();
    //QString trim_n_z(strbuf);
    strbuf.replace("\n","");
    strbuf.replace("\t"," ");
    list1 =strbuf.split(" ");
    qDebug()<<list1[1023]<<endl;

   // for(int i =0;i<1024;i++)
   // {
        //data[i]=databuf;
   // }
    Plot();
}
