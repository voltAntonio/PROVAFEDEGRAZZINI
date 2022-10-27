#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    bool checkIsNumber(QString xString);

    void on_squareButton_released();

    void on_doubleButton_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
