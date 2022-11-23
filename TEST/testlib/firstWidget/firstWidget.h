#ifndef FIRSTWIDGET_H
#define FIRSTWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class FirstWidget: public QWidget
{
    Q_OBJECT

    public:
        FirstWidget();
    private:
        QLineEdit* clayValue;
        QLineEdit* siltValue;
        QLineEdit* sandValue;

        bool checkIsNumber(QString xString, QString field, float &numeroInput);
        void checkSoil();
};

#endif // FIRSTWIDGET_H
