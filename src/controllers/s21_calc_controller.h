#pragma once

#include <array>
#include <stdexcept>
#include <iostream>

#include "../models/s21_calc_model.h"

namespace s21 {

class CalcController {
 public:
    CalcController() { calc_model = new s21::CalcModel; };
  // void Reset() noexcept { calc_model->Reset(); }
  bool Calculate(std::string &a);
  std::string GetResult() const noexcept { return std::to_string(calc_model->GetResult()); }

 private:
  s21::CalcModel *calc_model;
};

}  // namespace s21
