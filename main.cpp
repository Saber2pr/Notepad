#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle("Untitled");
    w.setMinimumSize(400, 299);
    w.setMaximumSize(960, 640);

    return a.exec();
}
