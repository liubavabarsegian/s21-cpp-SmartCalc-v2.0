#pragma once

#include <array>
#include <stdexcept>

#include "models/s21_calc_model.h"

namespace s21 {

class CalcController {
 public:
  CalcController(s21::CalcModel *m) : calc_model(m) {};
  void Reset() noexcept { calc_model->Reset(); }
  void StartCalc(const std::string &a, const double x);
  double GetResult() const noexcept { return calc_model->GetData(); }

 private:
  s21::CalcModel *calc_model;
};

}  // namespace s21
