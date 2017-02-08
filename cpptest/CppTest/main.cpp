#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.initDriver();
    w.initUi();
    w.show();

    return a.exec();
}
