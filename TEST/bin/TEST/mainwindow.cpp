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

float risul;

bool MainWindow::checkIsNumber(QString xString)
{
    if(xString == "")
    {
        QMessageBox::warning(this,"Warning","Missing number");
        return false;
    }
    bool isNumber = true;
    risul = xString.toFloat(&isNumber);
    if(!isNumber)
    {
        QMessageBox::warning(this,"Warning","Wrong number");
    }
    return isNumber;
}

void MainWindow::on_squareButton_released()
{
    //QString xString = ui->inputEdit->text();
    /*
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
    */

    if(checkIsNumber(ui->inputEdit->text()))
    {
        Square mySquareLib;
        //float x = ui->inputEdit->text().toFloat();
        mySquareLib.test(&risul);
        ui->outputEdit->setText(QString::number(risul));
    }
}


void MainWindow::on_doubleButton_released()
{
    /*
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
    */
    if(checkIsNumber(ui->inputEdit->text()))
    {
        Sum mySumLib;
        //float x = ui->inputEdit->text().toFloat();
        mySumLib.test(&risul);
        ui->outputEdit->setText(QString::number(risul));
    }
}
