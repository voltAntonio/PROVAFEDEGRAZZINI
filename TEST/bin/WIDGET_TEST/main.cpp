#include <QApplication>

#include "firstWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstWidget w;
    w.show();

    return a.exec();
}

