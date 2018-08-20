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
 //   ui->tableWidget->setColumnWidth(0,this->width()*2/3);
     ui->tableWidget->horizontalHeader()->setResizeContentsPrecision(QHeaderView::ResizeToContents);
     ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addTask_clicked()
{
    ui->tableWidget->insertRow( ui->tableWidget->rowCount());
    // colum 1
    ui->tableWidget->setItem ( ui->tableWidget->rowCount()-1,0,
                             new QTableWidgetItem(ui -> addTodo -> text()));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // colum 2
    QProgressBar *mybar = new QProgressBar();
    mybar ->setValue(ui->mainslider->value());
    ui->tableWidget->setCellWidget( ui -> tableWidget -> rowCount()-1 ,1 , mybar);
    //ui->tableWidgetItem->setBlocked(True);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //qDebug() << ui->mainslider->value();
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    QTableWidgetItem *editItem = ui->tableWidget->item(row,column);

    qDebug() << editItem;
}

void MainWindow::on_saveBtn_clicked()
{

}

