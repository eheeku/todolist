#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QMenuBar>
#include <iostream>

#include <qprogressbar.h>
#include <QFile>

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

     read_file();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::read_file()
{
    QString ApplicationPath=QApplication::applicationDirPath();
    qDebug() << ApplicationPath;
    QFile File(ApplicationPath+"/../todolist/DataFile/inputData.txt");
    if(!File.open(QFile::ReadOnly|QFile::Text)) // 읽기 전용, 텍스트로 파일 열기
        {
        if(!File.exists()) // 파일이 존재하지 않으면...
            { // 파일이 존재하지 않으면...여기에 동작 적용
                qDebug() <<"no file" << endl;
            }
        else
            {
                qDebug() <<"do not open file" << endl;
                // 파일을 열수 없거나 파일 손상 등 여러 요인작용...
            }
        }
    QTextStream OpenFile(&File);QString ConfigText;while(!OpenFile.atEnd()) // 파일 끝까지 읽어서
    {
        ConfigText=OpenFile.readLine(); // 한라인씩 읽어서 변수에 적용
        qDebug () << ConfigText << endl;
    }
    File.close(); // 파일닫기
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



/*
void MainWindow::createMenus(){
    //menubar
    QMenuBar *menuBar = new QMenuBar (0);

}
*/
