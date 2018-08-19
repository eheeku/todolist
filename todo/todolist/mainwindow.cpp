#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveBtn_clicked()
{
    QString add_text;
    add_text=ui -> addTodo -> text();
    ui->tableWidget->insertRow( ui->tableWidget->rowCount());
    ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1,
                             0,
                             new QTableWidgetItem(add_text));
}
