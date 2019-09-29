#ifndef COMTEST_H
#define COMTEST_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ComTest; }
QT_END_NAMESPACE

class ComTest : public QMainWindow
{
    Q_OBJECT

public:
    ComTest(QWidget *parent = nullptr);
    ~ComTest();

private:
    Ui::ComTest *ui;
};
#endif // COMTEST_H
