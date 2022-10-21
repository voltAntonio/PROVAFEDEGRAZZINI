#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "square.h"
#include "sum.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_squareButton_released()
{
    QString xString = ui->inputEdit->text();
    if(xString == "")
    {
        QMessageBox::warning(this,"Warning","Missing number");
        return;
    }
    bool isNumber;
    float x = xString.toFloat(&isNumber);
    if(!isNumber)
    {
        QMessageBox::warning(this,"Warning","Wrong number");
        return;
    }

    Square mySquareLib;
    float result = mySquareLib.test(x);
    ui->outputEdit->setText(QString::number(result));
}


void MainWindow::on_doubleButton_released()
{
    QString xString = ui->inputEdit->text();
    if(xString == "")
    {
        QMessageBox::warning(this,"Warning","Missing number");
        return;
    }
    bool isNumber;
    float x = xString.toFloat(&isNumber);
    if(!isNumber)
    {
        QMessageBox::warning(this,"Warning","Wrong number");
        return;
    }

    Sum mySumLib;
    float result = mySumLib.test(x);
    ui->outputEdit->setText(QString::number(result));
}

