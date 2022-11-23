#include "firstWidget.h"

#include <QString>

#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>

#include "QMessageBox"
#include "soil.h"


FirstWidget::FirstWidget()
{
    this->setWindowTitle(QStringLiteral("TEST"));
    this->resize(600, 600);

    clayValue = new QLineEdit;       //scatoli vuoti dove inserire testo o numeri.
    siltValue = new QLineEdit;
    sandValue = new QLineEdit;
    QLabel *labelClay = new QLabel(tr("Clay (%)"));             //Etichette sopra le scatole.
    QLabel *labelSilt = new QLabel(tr("Silt (%)"));
    QLabel *labelSand = new QLabel(tr("Sand (%)"));
    QPushButton *checkButton = new QPushButton(tr("Check")); //Il bottone per l'azione.
    QGridLayout *WidgetLayout = new QGridLayout;    //Posizionamento delle features.

    WidgetLayout->addWidget(labelClay, 0 , 0);
    WidgetLayout->addWidget(clayValue, 1 , 0);
    WidgetLayout->addWidget(labelSilt, 2 , 0);
    WidgetLayout->addWidget(siltValue, 3 , 0);
    WidgetLayout->addWidget(labelSand, 4 , 0);
    WidgetLayout->addWidget(sandValue, 5 , 0);
    WidgetLayout->addWidget(checkButton, 3 , 1);

    this->setLayout(WidgetLayout);

    connect(checkButton, &QPushButton::clicked, this, &FirstWidget::checkSoil);

}

bool FirstWidget::checkIsNumber(QString xString, QString field, float &valoreInput)
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

void FirstWidget::checkSoil()
{
    float resultClay, resultSilt, resultSand;
    QStringList materiale = { "clay", "silt", "sand" };

    if(checkIsNumber(clayValue->text(), materiale[0], resultClay) && checkIsNumber(siltValue->text(), materiale[1], resultSilt) && checkIsNumber(sandValue->text(), materiale[2], resultSand))
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
