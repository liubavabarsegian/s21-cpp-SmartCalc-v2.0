#ifndef CALCVIEW_H
#define CALCVIEW_H

// #include <QDialog>
#include <QWidget>
#include "controllers/s21_calc_controller.h"

namespace Ui {
class CalcView;
}

class CalcView : public QWidget
{
    Q_OBJECT

 public:
  explicit CalcView(QWidget *parent = nullptr);
  CalcView(QWidget *parent, s21::CalcController *controller);
  ~CalcView();
  Ui::CalcView *ui;

 private:
  void Append(QString text);
  void ShowGraphic();
  void BackspaceClicked();
  void Clear();
  void Equal();
};

#endif // CALCVIEW_H
