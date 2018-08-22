#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_addTask_clicked();

    int on_tableWidget_cellClicked(int row);


    void on_removeBtn_clicked();

    void on_saveBtn_clicked();
    void read_file();
    void write_file();

    void on_commandLinkButton_clicked();

private:
    Ui::MainWindow *ui;
    //void createMenus();
};


#endif // MAINWINDOW_H
