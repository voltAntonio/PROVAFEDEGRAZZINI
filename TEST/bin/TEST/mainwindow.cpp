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


bool MainWindow::checkIsNumber(QString xString, QString field, float &valoreInput)
{
    if(xString == "")
    {
        QMessageBox::warning(this,"Warning", field + " missing");
        return false;
    }
    bool isNumber = true;
    valoreInput = xString.toFloat(&isNumber);
    if(!isNumber)
    {
        QMessageBox::warning(this,"Warning","Wrong " + field);
    }
    return isNumber;
}

void MainWindow::on_squareButton_released()
{
    float result;
    QString campo = "value";

    if(checkIsNumber(ui->inputEdit->text(), campo, result))
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
    QString campo = "value";
    if(checkIsNumber(ui->inputEdit->text(), campo, result))
    {
        Sum mySumLib;
        //float x = ui->inputEdit->text().toFloat();
        mySumLib.test(result);
        ui->outputEdit->setText(QString::number(result));
    }
}


void MainWindow::on_textureButton_released()
{
    float resultClay, resultSilt, resultSand;
    QStringList materiale = { "clay", "silt", "sand" };

    if(checkIsNumber(ui->clayEdit->text(), materiale[0], resultClay) && checkIsNumber(ui->siltEdit->text(), materiale[1], resultSilt) && checkIsNumber(ui->sandEdit->text(), materiale[2], resultSand))
    {
        if(resultClay >=0 && resultSand >= 0 && resultSilt >= 0)
        {
            SoilTexture mySoilLib;

            mySoilLib.clay = resultClay;
            mySoilLib.sand = resultSand;
            mySoilLib.silt = resultSilt;

            if(checkTexture(mySoilLib, 1))
            {
               QMessageBox::information(this, "", "OK!");
            }
            else
            {
                QMessageBox::warning(this,"Warning", "Wrong values. Sum should be 100.");
            }
        }
        else
        {
            QMessageBox::warning(this,"Warning","Negative numbers not accepted!");
        }
    }
}

