#include "creditview.h"
#include "ui_creditview.h"

namespace s21{
CreditView::CreditView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreditView)
{
    ui->setupUi(this);
}

CreditView::~CreditView()
{
    delete ui;
}
} // namespace s21
