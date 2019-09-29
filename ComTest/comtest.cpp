#include "comtest.h"
#include "ui_comtest.h"

ComTest::ComTest(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ComTest)
{
    ui->setupUi(this);
}

ComTest::~ComTest()
{
    delete ui;//
}

