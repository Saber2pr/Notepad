#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>

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

private:
    Ui::MainWindow *ui;
    QString path_current;

    void saveCurrentFile();

    void createNewFile();

};

#endif // MAINWINDOW_H
