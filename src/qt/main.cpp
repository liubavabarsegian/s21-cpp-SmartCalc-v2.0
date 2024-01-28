#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow calc_view(nullptr);
  calc_view.show();
  return a.exec();
}
