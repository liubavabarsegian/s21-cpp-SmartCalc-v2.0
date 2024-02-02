#include "s21_credit_calc.h"

void CreditCalculator::SetStartValues(long double loan, int period,
                                      long double rate) {
  loan_ = loan;
  period_ = period;
  rate_ = rate;
}

void CreditCalculator::CalcAnnuity() {
  month_payment_ = CalcMonthAnnuity();
  total_payment_ = month_payment_ * period_;
  overpayment_ = total_payment_ - loan_;
}

void CreditCalculator::CalcDifferentiated() {
  long double Sn = loan_ / period_;
  long double percent =
      rate_ / 100 * (days_in_year_ / months_in_year_) / days_in_year_;
  total_payment_ = 0;

  for (int i = 0; i < period_; i++) {
    long double payment = Sn + (loan_ - i * Sn) * percent;
    if (i == 0) {
      first_payment_ = payment;
    } else {
      last_payment_ = payment;
    }
    total_payment_ += payment;
  }

  overpayment_ = total_payment_ - loan_;
}

long double CreditCalculator::CalcMonthAnnuity() {
  long double month_rate = rate_ / 12.0 / 100.0;
  long double temp = std::pow((1 + month_rate), period_);

  return loan_ * month_rate * temp / (temp - 1);
}
