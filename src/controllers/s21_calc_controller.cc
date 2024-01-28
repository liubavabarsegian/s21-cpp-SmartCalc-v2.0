#include "s21_calc_controller.h"

namespace s21 {

bool s21::CalcController::Calculate(std::string &input) {
  try {
    return calc_model->Calculate(input);
  } catch (const std::exception &e) {
    throw std::runtime_error(e.what());
    return false;
  }
}
}  // namespace s21