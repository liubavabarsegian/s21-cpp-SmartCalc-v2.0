#ifndef CREDITVIEW_H
#define CREDITVIEW_H

#include <QWidget>

namespace Ui {
class CreditView;
}

namespace s21{
class CreditView : public QWidget
{
    Q_OBJECT

public:
    explicit CreditView(QWidget *parent = nullptr);
    ~CreditView();

private:
    Ui::CreditView *ui;
};
} //namespace s21

#endif // CREDITVIEW_H
