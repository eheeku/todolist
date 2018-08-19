#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
//    void on_addTodo_textEdited(const QString &arg1);

    void on_saveBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
