#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include<./src/CodeColor/codecolor.h>
#include<memory>

namespace Ui {
class MainWindow;
}
/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /**
     * @brief on_textEdit_textChanged
     */
    void on_textEdit_textChanged();
    /**
     * @brief on_pushButton_clicked
     */
    void on_pushButton_clicked();
    /**
     * @brief openFile
     */
    void openFile();
    /**
     * @brief closeFile
     */
    void closeFile();
    /**
     * @brief showAbout
     */
    void showAbout();

private:
    Ui::MainWindow *ui;
    /**
     * @brief path_current
     */
    QString path_current;
    /**
     * @brief coder
     */
    std::shared_ptr<CodeColor> coder;
    /**
     * @brief text_pre
     */
    QString text_pre;
    /**
     * @brief saveCurrentFile
     */
    void saveCurrentFile();
    /**
     * @brief createNewFile
     */
    void createNewFile();
    /**
     * @brief displayCurrent
     */
    void displayCurrent();
    /**
     * @brief initTextEdit
     */
    void initTextEdit();

};

#endif // MAINWINDOW_H
