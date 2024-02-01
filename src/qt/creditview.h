#pragma once

#include <QWidget>

#include "../controllers/s21_credit_controller.h"

namespace Ui {
class CreditView;
}

namespace s21 {
class CreditView : public QWidget {
  Q_OBJECT

 public:
  explicit CreditView(QWidget *parent = nullptr);
  ~CreditView();

 private:
  Ui::CreditView *ui;
  s21::CreditController *credit_controller;
  void Calculate();
};
}  // namespace s21
