#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qprogressbar.h>
#include <iostream>
 using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,this->width()*2/3);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveBtn_clicked()
{
    ui->tableWidget->insertRow( ui->tableWidget->rowCount());
    // colum 1
    ui->tableWidget->setItem ( ui->tableWidget->rowCount()-1,0,
                             new QTableWidgetItem(ui -> addTodo -> text()));

    // colum 2
    QProgressBar *mybar = new QProgressBar();
    mybar ->setValue(ui->mainslider->value());
    ui->tableWidget->setCellWidget( ui -> tableWidget -> rowCount()-1 ,1 , mybar);

    qDebug() << ui->mainslider->value();
}
