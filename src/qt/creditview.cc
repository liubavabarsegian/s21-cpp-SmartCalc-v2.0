#include "creditview.h"

#include "ui_creditview.h"

namespace s21 {
CreditView::CreditView(QWidget *parent)
    : QWidget(parent), ui(new Ui::CreditView) {
  credit_controller = new s21::CreditController;

  ui->setupUi(this);
  connect(ui->calc_btn, &QPushButton::clicked, this, [this] { Calculate(); });
}

CreditView::~CreditView() { delete ui; }

void CreditView::Calculate() {
  ui->monthly_payment_val->setText("");
  ui->overpayment_val->setText("");
  ui->total_payment_val->setText("");

  const double period = ui->period_val->text().toDouble();
  const double loan = ui->amount_val->text().toDouble();
  const double rate = ui->interest_rate->text().toDouble();

  credit_controller->SetStartValues(loan, period, rate);
  if (ui->annuity->isChecked()) {
    credit_controller->CalcAnnuity();
    ui->monthly_payment_val->setText(
        QString("%L1").arg(credit_controller->GetMonthPayment(), 0, 'f', 2));
    ui->overpayment_val->setText(
        QString("%L1").arg(credit_controller->GetOverpayment(), 0, 'f', 2));
    ui->total_payment_val->setText(
        QString("%L1").arg(credit_controller->GetTotalPayment(), 0, 'f', 2));
  } else if (ui->diff->isChecked()) {
    credit_controller->CalcDifferentiated();
    ui->monthly_payment_val->setText(
        QString("%L1").arg(credit_controller->GetMonthPayment(), 0, 'f', 2));
    ui->overpayment_val->setText(
        QString("%L1").arg(credit_controller->GetOverpayment(), 0, 'f', 2));
    ui->total_payment_val->setText(
        QString("%L1").arg(credit_controller->GetTotalPayment(), 0, 'f', 2));
  }
}
}  // namespace s21
