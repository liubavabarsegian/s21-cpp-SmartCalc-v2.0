#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>

extern "C" int scan_rpn(char *inp, char *result);

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  Ui::MainWindow *ui;

 private:
  void append(QString text);
  void show_graphic();
  void clicked_backspace();
  void clear();
  void equal();
};
#endif  // MAINWINDOW_H
