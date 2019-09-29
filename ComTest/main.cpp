#include "comtest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ComTest w;
    w.show();
    return a.exec();
}
