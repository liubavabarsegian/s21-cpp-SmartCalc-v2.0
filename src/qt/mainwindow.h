#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../controllers/s21_calc_controller.h"
#include "qcustomplot.h"
#include "../controllers/s21_calc_controller.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, s21::CalcController *calc_controller);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    s21::CalcController *controller;
    void Append(QString text);
    void ShowGraphic();
    void BackspaceClicked();
    void Clear();
    void Equal();
};

#endif // MAINWINDOW_H
