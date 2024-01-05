#pragma once

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace s21 {
class CaclView;
}
QT_END_NAMESPACE

class CaclView : public QMainWindow {
  Q_OBJECT

 public:
  CaclView(QWidget *parent = nullptr);
  ~CaclView();
  Ui::CaclView *ui;

 private:
  void Append(QString text);
  void ShowGraphic();
  void BackspaceClicked();
  void Clear();
  void Equal();
};
