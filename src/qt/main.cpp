#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  s21::CalcModel calc_model;
  s21::CalcController calc_controller(&calc_model);
  s21::CreditView credit_view;
  MainWindow w(nullptr, &calc_controller, &credit_view);
  w.show();
  return a.exec();
}
