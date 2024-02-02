#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QLocale::setDefault(QLocale::C);
  setenv("LC_NUMERIC", "C",1); 
  QApplication a(argc, argv);
  MainWindow w(nullptr);
  w.show();
  return a.exec();
}
