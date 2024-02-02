#pragma once
#include "../models/s21_credit_calc.h"

namespace s21 {
class CreditController {
 public:
  CreditController() = default;
  ~CreditController() = default;

  void SetStartValues(long double loan, long double period, long double rate);
  void CalcAnnuity();
  void CalcDifferentiated();
  long double GetMonthPayment();
  long double GetOverpayment();
  long double GetTotalPayment();
  long double GetFirstPayment();
  long double GetLastPayment();

 private:
  CreditCalculator credit_calc;
};
};  // namespace s21
