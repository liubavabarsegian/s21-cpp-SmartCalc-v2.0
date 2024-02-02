
#ifndef SMARTCALC_CPP_SRC_MODEL_CREDITCALCULATOR_H
#define SMARTCALC_CPP_SRC_MODEL_CREDITCALCULATOR_H

#include <time.h>

#include <cmath>

class CreditCalculator {
 public:
  CreditCalculator() = default;
  CreditCalculator(long double loan, int period, long double rate)
      : loan_(loan), period_(period), rate_(rate){};
  ~CreditCalculator() = default;

  void SetStartValues(long double loan, int period, long double rate);
  void CalcAnnuity();
  void CalcDifferentiated();
  long double GetMonthPayment() { return month_payment_; }
  long double GetTotalPayment() { return total_payment_; }
  long double GetOverpayment() { return overpayment_; }
  long double GetFirstPayment() { return first_payment_; }
  long double GetLastPayment() { return last_payment_; }

 private:
  long double CalcMonthAnnuity();
  long double loan_{};
  int period_{};
  long double rate_{};
  long double first_payment_{}, last_payment_{};
  long double month_payment_{}, total_payment_{}, overpayment_{};
  static constexpr int days_in_year_ = 365;
  static constexpr long double months_in_year_ = 12.0;
};

#endif  // SMARTCALC_CPP_SRC_MODEL_CREDITCALCULATOR_H
