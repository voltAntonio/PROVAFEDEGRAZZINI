#include "firstWidget.h"

#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>
#include "QMessageBox"
#include <QGroupBox>

#include "soil.h"


FirstWidget::FirstWidget()
{
    this->setWindowTitle(QStringLiteral("TEST"));
    this->resize(600, 300);

    clayValue = new QLineEdit;       //scatoli vuoti dove inserire testo o numeri.
    siltValue = new QLineEdit;
    sandValue = new QLineEdit;
    tolleranza = new QLineEdit;
    tolleranza->setText("1");       //era meglio inserirla nella soiltexture come le altre per poi passargli il valore dell'utente?

    QLabel *labelClay = new QLabel(tr("Clay (%)"));             //Etichette sopra le scatole.
    QLabel *labelSilt = new QLabel(tr("Silt (%)"));
    QLabel *labelSand = new QLabel(tr("Sand (%)"));
    QPushButton *checkButton = new QPushButton(tr("Check")); //Il bottone per l'azione.
    QHBoxLayout *LayoutOrizz = new QHBoxLayout();
    QVBoxLayout *VertLayout = new QVBoxLayout();
    QGridLayout *soilLayout = new QGridLayout;    //Posizionamento delle features.
    QGroupBox *contenitoreUno = new QGroupBox(tr("soil"));
    QGroupBox *contenitoreDue = new QGroupBox(tr("tolerance"));

    soilLayout->addWidget(labelClay, 0 , 0);
    soilLayout->addWidget(clayValue, 1 , 0);
    soilLayout->addWidget(labelSilt, 2 , 0);
    soilLayout->addWidget(siltValue, 3 , 0);
    soilLayout->addWidget(labelSand, 4 , 0);
    soilLayout->addWidget(sandValue, 5 , 0);
    soilLayout->addWidget(checkButton, 3 , 1);

    VertLayout->addWidget(tolleranza);

    contenitoreUno->setMaximumSize(200, 200);
    contenitoreUno->setLayout(soilLayout);

    contenitoreDue->setMaximumSize(200, 200);
    contenitoreDue->setLayout(VertLayout);

    LayoutOrizz->addWidget(contenitoreUno);
    LayoutOrizz->addWidget(contenitoreDue);
    this->setLayout(LayoutOrizz);

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
    float resultClay, resultSilt, resultSand, resultTolerance;
    QStringList materiale = { "clay", "silt", "sand", "tolerance" };

    if(checkIsNumber(clayValue->text(), materiale[0], resultClay) && checkIsNumber(siltValue->text(), materiale[1], resultSilt) && checkIsNumber(sandValue->text(), materiale[2], resultSand) && checkIsNumber(tolleranza->text(), materiale[3], resultTolerance))
    {
        if(resultClay >=0 && resultSand >= 0 && resultSilt >= 0 && resultTolerance >= 0)
        {
            if(resultTolerance > 10)
            {
                QMessageBox::warning(this,"Warning", "Tolerance cannot exceed 10.");
            }
            else
            {
                SoilTexture mySoilLib;

                mySoilLib.clay = resultClay;
                mySoilLib.sand = resultSand;
                mySoilLib.silt = resultSilt;

                double somma;

                if(checkTexture(mySoilLib, somma, resultTolerance))
                {
                   QMessageBox::information(this, "", "OK!");
                }
                else
                {
                    QMessageBox::warning(this,"Warning", "Wrong values. Sum should be 100. Now sum is: " + QString::number(somma));
                }
            }
        }
        else
        {
            QMessageBox::warning(this,"Warning","Negative numbers not accepted!");
        }
    }
}

/*
Per complicare un poco le cose (altrimenti è troppo facile :-) :

Nel secondo box (che chiamiamo tolerance)  metti un QlineEdit in cui inserire la soglia di tolleranza da passare alla checkTexture()
in partenza quindi nel lineEdit ci deve essere il valore 1, che uno può modificare
serve anche qui un controllo (da fare sempre quando clicchi sul bottone check) che sia stato inserito un numero, che non sia negativo
e anche che non sia maggiore di 10 (soglia massima).
Poi quando ritorni dalla  chekTexture  , nel caso restituisca false, nel messaggio di errore fai comparire anche quanto è ora la somma ("Now sum is: valore)
per farlo puoi passare alla chekTexture un double currentSum per riferimento, in cui salverai il valore.
*/
