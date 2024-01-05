#pragma once

#include <array>
#include <clocale>
#include <cmath>
#include <memory>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <iostream>
#include <algorithm>

namespace s21 {

class CalcModel {
 public:
  CalcModel() {};
  virtual ~CalcModel() {};
  bool Dijkstra(const std::string& input);
  bool ScanRpn(const std::string& input, std::string& result);


 private:
  std::stack<std::string> operators_stack_{};
  std::stack<double> values_stack_{};
  double result_{};
  bool IsFunction(std::string str) noexcept;
  bool IsDelim(char c) noexcept;
  bool GetOperatorPriority(std::string);
  std::string GetToken(std::string token, std::string prog, size_t& i);
  bool InsertTokenToStack(std::string token);
  bool Sum();
  bool Multiplication();
  bool Division();
  bool Difference();
  bool Mod();
  bool Power();
  bool Sinus();
  bool Cosinus();
  bool Tangent();
  bool Atangent();
  bool Asinus();
  bool Acosinus();
  bool Square();
  bool LnFunc();
  bool LogFunc();
  bool CountFunction();
  int CountChars(const std::string& str, char c);
  bool Calculate();
  bool Unaries(const std::string& input, std::string& dest);
};

}  // namespace s21



