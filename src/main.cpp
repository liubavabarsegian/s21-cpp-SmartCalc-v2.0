#include <QApplication>

#include "calcview.h"
#include "models/s21_calc_model.h"
#include "controllers/s21_calc_controller.h"

int main(int argc, char *argv[]) {
  s21::CalcModel calc_model;
  s21::CalcController calc_controller(&calc_model);
  QApplication a(argc, argv);
  CalcView calc_view(nullptr);
  calc_view.show();
  return a.exec();
}
