#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
 using namespace std;
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
    ui->tableWidget->insertRow( ui->tableWidget->rowCount());
    ui->tableWidget->setItem ( ui->tableWidget->rowCount()-1,0,
                             new QTableWidgetItem(ui -> addTodo -> text()));

//    QProgressBar *myslider = new QProgressBar ();
//    myslider->setValue(ui->mainslider->value());


  //  ui->tableWidget->setItem ( ui->tableWidget->rowCount()-1,1,
    //                         new QTableWidgetItem(myslider));

    qDebug() << ui->mainslider->value();
}
