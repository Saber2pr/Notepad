#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"./src/utils/console.hpp"
#include"./src/LocalConnect/local.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));

    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(closeFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEdit_textChanged()
{

}

void MainWindow::on_pushButton_clicked()
{
    if(!this->path_current.isNull()){
        this->saveCurrentFile();
    }else {
        this->createNewFile();
        if(!this->path_current.isNull()){
            this->saveCurrentFile();
            this->setWindowTitle(QFileInfo(this->path_current).fileName());
        }
    }
}

void MainWindow::openFile(){
    QString file_path = QFileDialog::getOpenFileName(this, "open", "", tr("Config Files (*.txt)"));
    if(!file_path.isNull()){
        this->path_current = file_path;
        Local::getInstance()->connect(this->path_current.toStdString())([=](auto data){
            ui->textEdit->setText(QString::fromStdString(data));
        });
        this->setWindowTitle(QFileInfo(this->path_current).fileName());
    }
}

void MainWindow::closeFile(){
    this->path_current = QString::null;
    ui->textEdit->setText(QString::null);
    this->setWindowTitle("Untitled");
}

void MainWindow::saveCurrentFile(){
    string input = ui->textEdit->toPlainText().toStdString();
    Local::getInstance()->connect(this->path_current.toStdString(), input)([=](auto data){
        ui->textEdit->setText(QString::fromStdString(data));
    });
    ui->statusBar->showMessage(tr("save successfully"), 1000);
}

void MainWindow::createNewFile(){
    this->path_current = QFileDialog::getSaveFileName(this, "create new file", "", tr("Config Files (*.txt)"));
}
