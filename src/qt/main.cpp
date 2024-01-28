#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  s21::CalcModel calc_model;
  s21::CalcController calc_controller(&calc_model);

  QApplication a(argc, argv);
  MainWindow w(nullptr, &calc_controller);
  w.show();
  return a.exec();
}
