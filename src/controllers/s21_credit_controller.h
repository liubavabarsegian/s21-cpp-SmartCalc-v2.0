#ifndef SMARTCALC_CPP_SRC_CONTROLLERCREDIT_H
#define SMARTCALC_CPP_SRC_CONTROLLERCREDIT_H

#include "../models/s21_credit_calc.h"

namespace s21 {
class CreditController {
 public:
  CreditController() = default;
  ~CreditController() = default;

  void SetStartValues( double loan,  double period,  double rate);
  void CalcAnnuity();
  void CalcDifferentiated();
  double GetMonthPayment();
  double GetOverpayment();
  double GetTotalPayment();
  double GetFirstPayment();
  double GetLastPayment();

 private:
  CreditCalculator credit_calc;
};
}
#endif  // SMARTCALC_CPP_SRC_CONTROLLERCREDIT_H