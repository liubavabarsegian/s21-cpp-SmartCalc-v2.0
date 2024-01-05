#include <QApplication>

#include "views/s21_calc_view.h"
#include "models/s21_calc_model.h"
#include "controllers/s21_calc_controller.h"

int main(int argc, char *argv[]) {
  s21::CalcModel calc_model;
  s21::CalcController calc_controller(&calc_model);
  QApplication a(argc, argv);
  MainWindow w(nullptr, &calc_controller);
  w.show();
  return a.exec();
}
