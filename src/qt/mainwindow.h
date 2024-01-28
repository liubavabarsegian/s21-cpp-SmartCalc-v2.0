#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../controllers/s21_calc_controller.h"
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    MainWindow(QWidget *parent, s21::CalcController *controller);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void Append(QString text);
    void ShowGraphic();
    void BackspaceClicked();
    void Clear();
    void Equal();
};

#endif // MAINWINDOW_H
