#include "mainwindow.h"
#include <QApplication>
#include<QTextCodec>
#include"./src/PathResolver/pathresolver.h"

int main(int argc, char *argv[])
{
    if(argv[1] != NULL){
        PathResolver::getInstance()->value = argv[1];
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setMinimumSize(400, 299);
    w.setWindowIcon(QIcon("./favicon.ico"));

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

    return a.exec();
}
