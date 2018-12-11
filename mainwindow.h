#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include<./src/CodeColor/codecolor.h>
#include<memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_textEdit_textChanged();
    void on_pushButton_clicked();

    void openFile();
    void closeFile();
    void showAbout();

private:
    Ui::MainWindow *ui;
    QString path_current;
    std::shared_ptr<CodeColor> coder;
    QString text_pre;

    void saveCurrentFile();
    void createNewFile();

    void initTextEdit();

};

#endif // MAINWINDOW_H
