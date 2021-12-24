#include "snowwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SnowWidget w;

    w.show();
    Sleep(7000);
    return a.exec();
}
