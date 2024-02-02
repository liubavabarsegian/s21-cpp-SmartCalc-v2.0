#include "s21_credit_controller.h"

namespace s21 {
void CreditController::SetStartValues(long double loan, long double period,
                                      long double rate) {
  credit_calc.SetStartValues(loan, period, rate);
}

void CreditController::CalcAnnuity() { credit_calc.CalcAnnuity(); }

void CreditController::CalcDifferentiated() {
  credit_calc.CalcDifferentiated();
}

long double CreditController::GetMonthPayment() {
  return credit_calc.GetMonthPayment();
}

long double CreditController::GetOverpayment() {
  return credit_calc.GetOverpayment();
}

long double CreditController::GetTotalPayment() {
  return credit_calc.GetTotalPayment();
}

long double CreditController::GetFirstPayment() {
  return credit_calc.GetFirstPayment();
}

long double CreditController::GetLastPayment() {
  return credit_calc.GetLastPayment();
}
}  // namespace s21
