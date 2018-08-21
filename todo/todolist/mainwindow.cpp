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


     //table resize
     ui->tableWidget->setColumnWidth(0,305);
     ui->tableWidget->setColumnWidth(1,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addTask_clicked()
{
    ui->tableWidget->insertRow( ui->tableWidget->rowCount());

    // colum 1
    QProgressBar *mybar = new QProgressBar(ui->tableWidget);
    mybar-> setValue(ui->mainslider->value());
    ui->tableWidget->setCellWidget( ui -> tableWidget -> rowCount()-1 ,0, mybar);
    // colum 2
    ui->tableWidget->setItem ( ui->tableWidget->rowCount()-1, 1,
                             new QTableWidgetItem(ui -> addTodo -> text()));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


    //debug
    qDebug() << "success add list"<< endl;
    qDebug() << "bar addr:"<< ui->tableWidget->item(ui->tableWidget->rowCount()-1, 0)
             << "text addr:" <<ui->tableWidget->item(ui->tableWidget->rowCount()-1, 1)<<endl;
}

int MainWindow::on_tableWidget_cellClicked(int row)
{

    //column0 edit
    ui->mainslider->setValue((qobject_cast<QProgressBar*>(ui->tableWidget->cellWidget(row,0)))->value());

    //colum1 edit
    QTableWidgetItem *editItem1 = ui->tableWidget->item(row,1);
    ui->addTodo->setText(editItem1->text());

   qDebug() << "Success clicked bar"<<endl;
}


void MainWindow::on_removeBtn_clicked(){ui->tableWidget->removeRow(ui->tableWidget->currentRow());}

void MainWindow::on_saveBtn_clicked()
{
    // get click row : ui->tableWidget->currentRow()
    // colum 1
    QProgressBar *mybar = new QProgressBar(ui->tableWidget);
    mybar-> setValue(ui->mainslider->value());
    ui->tableWidget->setCellWidget( ui->tableWidget->currentRow() ,0, mybar);
    // colum 2
    ui->tableWidget->setItem ( ui->tableWidget->currentRow(), 1,
                             new QTableWidgetItem(ui -> addTodo -> text()));
}
