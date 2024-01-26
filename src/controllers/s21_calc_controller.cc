#include "s21_calc_controller.h"

namespace s21 {

void s21::CalcController::Calculate(std::string &input) {
  try {
    calc_model->Calculate(input);
  } catch (const std::exception &e) {
    throw std::runtime_error(e.what());
  }
}

}  // namespace s21
