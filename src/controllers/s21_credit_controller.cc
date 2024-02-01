#include "s21_credit_controller.h"

namespace s21 {
void CreditController::SetStartValues(double loan, double period, double rate) {
  credit_calc.SetStartValues(loan, period, rate);
}

void CreditController::CalcAnnuity() { credit_calc.CalcAnnuity(); }

void CreditController::CalcDifferentiated() {
  credit_calc.CalcDifferentiated();
}

double CreditController::GetMonthPayment() {
  return credit_calc.GetMonthPayment();
}

double CreditController::GetOverpayment() {
  return credit_calc.GetOverpayment();
}

double CreditController::GetTotalPayment() {
  return credit_calc.GetTotalPayment();
}

double CreditController::GetFirstPayment() {
  return credit_calc.GetFirstPayment();
}

double CreditController::GetLastPayment() {
  return credit_calc.GetLastPayment();
}
}  // namespace s21
