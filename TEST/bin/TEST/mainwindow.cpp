#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "square.h"
#include "sum.h"
#include "soil.h"

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


bool MainWindow::checkIsNumber(QString xString, float &valoreInput)
{
    if(xString == "")
    {
        QMessageBox::warning(this,"Warning","Missing number");
        return false;
    }
    bool isNumber = true;
    valoreInput = xString.toFloat(&isNumber);
    if(!isNumber)
    {
        QMessageBox::warning(this,"Warning","Wrong number");
    }
    return isNumber;
}

void MainWindow::on_squareButton_released()
{
    float result;
    if(checkIsNumber(ui->inputEdit->text(), result))
    {
        Square mySquareLib;
        //float x = ui->inputEdit->text().toFloat();
        mySquareLib.test(result);
        ui->outputEdit->setText(QString::number(result));
    }
}


void MainWindow::on_doubleButton_released()
{
    float result;
    if(checkIsNumber(ui->inputEdit->text(), result))
    {
        Sum mySumLib;
        //float x = ui->inputEdit->text().toFloat();
        mySumLib.test(result);
        ui->outputEdit->setText(QString::number(result));
    }
}
