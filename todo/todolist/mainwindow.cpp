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
    QFile File(ApplicationPath+"/../todolist/DataFile/inputData.txt");

    if(!File.open(QFile::ReadOnly|QFile::Text))
        {
        if(!File.exists()){ qDebug() <<"no file" << endl; }

        else {qDebug() <<"do not open file" << endl;}
        }

    QTextStream OpenFile(&File);
    QString ConfigText;
    QStringList textList;
    while(!OpenFile.atEnd())
    {
        textList = OpenFile.readLine().split("|");

        ui->tableWidget->insertRow( ui->tableWidget->rowCount());

        // colum 1
        QProgressBar *mybar = new QProgressBar(ui->tableWidget);
        mybar-> setValue(textList[0].toInt());
        ui->tableWidget->setCellWidget( ui -> tableWidget -> rowCount()-1 ,0, mybar);

        // colum 2
        ui->tableWidget->setItem ( ui->tableWidget->rowCount()-1, 1,
                                 new QTableWidgetItem(textList[1]));
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        qDebug () << "success read file data :";
        qDebug () << textList[0].toInt() <<textList[1] << endl;
    }
    File.close();
}


QString StrToQString(char *str){
    return QString::fromUtf8(str,strlen(str));
}

void MainWindow::write_file()
{
    QString ApplicationPath=QApplication::applicationDirPath();
    QFile File(ApplicationPath+"/../todolist/DataFile/outputData.txt");

    File.open(QFile::WriteOnly|QFile::Text);
    QTextStream SaveFile(&File);

    int i = 0;
    while (ui->tableWidget->rowCount()!=i){
        //column0 edit
        int val = ((qobject_cast<QProgressBar*>(ui->tableWidget->cellWidget(i,0)))->value());

        //colum1 edit
        QTableWidgetItem *editItem1 = ui->tableWidget->item(i,1);
        SaveFile <<val<<"|"<<editItem1->text() << endl;
        i++;
    }

    File.close();
    qDebug()<<"success file write"<<endl;
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
    write_file();

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

    write_file();
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

    write_file();
}



/*
void MainWindow::createMenus(){
    //menubar
    QMenuBar *menuBar = new QMenuBar (0);

}
*/
