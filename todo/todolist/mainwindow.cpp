#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //initialize tableWidget
    int colCount =2;
    int rowCount = 10;
    ui->tableWidget->setColumnCount(colCount);
    ui->tableWidget->setRowCount(rowCount);

    QTableWidgetItem *numberItem = new QTableWidgetItem();
    numberItem->setText("ID");
    ui->tableWidget->setHorizontalHeaderItem(0, numberItem);

    QTableWidgetItem *nameItem = new QTableWidgetItem();
    nameItem->setText("List");
    ui->tableWidget->setHorizontalHeaderItem(1, nameItem);
    //ui->addTodo->setText("hello eheeku!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveBtn_clicked()
{
    QString add_text;
    add_text=ui -> addTodo -> text();
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("0"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem(add_text));
    //QTableWidgetItem *newItem = new QTableWidgetItem ();
    //ui->tableWidget->setItem(1,1,newItem);
}
