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

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
