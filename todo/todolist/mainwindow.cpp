#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->addTodo->setText("hello eheeku!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveBtn_clicked()
{
 //   ui->label_2->setText("hi!");
    QString add_text;
    add_text=ui->addTodo->text();

    qDebug() << add_text;
}
