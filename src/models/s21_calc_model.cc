#include "s21_calc_model.h"

namespace s21 {

bool CalcModel::IsFunction(std::string str) noexcept {
  static const std::unordered_set<std::string> functions = {
      "sin", "cos", "tan", "asin", "acos", "atan", "sqrt", "log", "ln"};

  return functions.count(str) > 0;
}

bool CalcModel::IsDelim(char c) noexcept {
  static const std::unordered_set<char> delimeters = {
      ' ', '+', '-', '/', '*', '%', '^', '=', '(', ')', '\r', 9, 0};

  return delimeters.count(c) > 0;
}

bool CalcModel::GetOperatorPriority(std::string op) {
  if (op == "(")
    return 3;
  else if (op == "^")
    return 2;
  else if (IsFunction(op))
    return 2;
  else if (op == "*" || op == "/" || op == "%")
    return 1;
  else if (op == "+" || op == "-")
    return 0;
  else
    return -1;  // error: unknown operator
}

std::string CalcModel::GetToken(std::string &token, std::string &prog,
                                size_t& i) {
  if (!token.empty()) { token.clear(); }
  if (prog.empty()) return token;

  while (std::isspace(prog[0])) {
    prog.erase(0, 1);
    ++i;
  }
  if (prog.find_first_of("+-*/%^()") != std::string::npos) {
    token += prog[0];
    prog.erase(0, 1);
    ++i;
  } else if (std::isalpha(prog[0])) {
    while (!std::ispunct(prog[0]) && !std::isspace(prog[0])) {
      token += prog[0];
      prog.erase(0, 1);
      ++i;
    }
  } else if (std::isdigit(prog[0])) {
    while (prog[0] && !std::ispunct(prog[0]) && !std::isspace(prog[0])) {
      token += prog[0];
      prog.erase(0, 1);
      ++i;
    }
  }

  return token;
}

bool CalcModel::InsertTokenToStack(std::string token) {
  if (IsDelim(token[0]) || IsFunction(token)) {
    if (operators_stack_.empty()) {
      operators_stack_.push(token);
    } else {
      // Close brace
      if (token == ")") {
        if (values_stack_.empty() || operators_stack_.empty()) return false;

        while (!operators_stack_.empty() && operators_stack_.top() != "(") {
          if (!values_stack_.empty()) {
            values_stack_.pop();
          }

          operators_stack_.pop();
        }

        if (!operators_stack_.empty() && operators_stack_.top() == "(") {
          operators_stack_.pop();  // Pop the "("
        }
      } else {
        if (GetOperatorPriority(operators_stack_.top()) == -1 ||
            GetOperatorPriority(token) == -1)
          return false;

        // While the priority of O2 is higher than or equal to O1, move from
        // stack to RPN
        while (!operators_stack_.empty() && operators_stack_.top() != "(" &&
               GetOperatorPriority(operators_stack_.top()) >=
                   GetOperatorPriority(token)) {
          operators_stack_.pop();
        }

        operators_stack_.push(token);
      }
    }
  } else {
    std::string value;
    std::istringstream(token) >> value;
    values_stack_.push(value);
  }

  return true;
}

bool CalcModel::Dijkstra(std::string& input) {
  if (input.empty()) { return false; }

  size_t i = 0;
  std::string token = "";
  while (i < input.size()) {
    std::string tmp = input.substr(i);
    GetToken(token, tmp, i);
    if (token.empty() || !InsertTokenToStack(token)) {
      while (!operators_stack_.empty()) operators_stack_.pop();

      while (!values_stack_.empty()) values_stack_.pop();

      return false;
    }
    std::cout << "TOKEN" << token << std::endl;
  }

  std::string delim;
  while (!operators_stack_.empty()) {
    if (!values_stack_.empty()) {
      delim = operators_stack_.top();
      values_stack_.push(delim);
    }
    operators_stack_.pop();
  }

  // result_ = (!values_stack_.empty()) ? stod(values_stack_.top()) : 0.0;
  // std::cout << "RESULT_" << result_ << std::endl;
  return true;
}

bool CalcModel::Sum() {
  if (values_stack_.size() < 2) {
    return false;
  }

  double operand1 = stod(values_stack_.top());
  values_stack_.pop();

  double operand2 = stod(values_stack_.top());
  values_stack_.pop();

  double result = operand1 + operand2;

  result_.push(std::to_string(result));
  std::cout << "SUM res " << result_.top() << "\n";
  return true;
}

bool CalcModel::Division() {
  if (values_stack_.size() < 2) {
    return false;
  }

  double operand2 = stod(values_stack_.top());
  values_stack_.pop();

  double operand1 = stod(values_stack_.top());
  values_stack_.pop();

  if (operand2 == 0.0) {
    return false;
  }

  double result = operand1 / operand2;

  values_stack_.push(std::to_string(result));
  return true;
}

bool CalcModel::Multiplication() {
  if (values_stack_.size() < 2) {
    return false;
  }

  double operand1 = stod(values_stack_.top());
  values_stack_.pop();

  double operand2 = stod(values_stack_.top());
  values_stack_.pop();

  double result = operand1 * operand2;

  values_stack_.push(std::to_string(result));
  return true;
}

bool CalcModel::Difference() {
  if (values_stack_.size() < 2) {
    return false;
  }

  double operand2 = stod(values_stack_.top());
  values_stack_.pop();

  double operand1 = stod(values_stack_.top());
  values_stack_.pop();

  double result = operand1 - operand2;

  values_stack_.push(std::to_string(result));
  return true;
}

bool CalcModel::Mod() {
  if (values_stack_.size() < 2) {
    return false;
  }

  double operand2 = stod(values_stack_.top());
  values_stack_.pop();

  double operand1 = stod(values_stack_.top());
  values_stack_.pop();

  double result = fmod(operand1, operand2);

  values_stack_.push(std::to_string(result));
  return true;
}

bool CalcModel::Power() {
  if (values_stack_.size() < 2) {
    return false;
  }

  double exponent = stod(values_stack_.top());
  values_stack_.pop();

  double base = stod(values_stack_.top());
  values_stack_.pop();

  double result = pow(base, exponent);

  values_stack_.push(std::to_string(result));
  return true;
}

bool CalcModel::Sinus() {
  if (values_stack_.empty()) {
    return false;
  }

  double angle = stod(values_stack_.top());
  values_stack_.pop();

  double result = sin(angle);

  values_stack_.push(std::to_string(result));
  return true;
}

bool CalcModel::Cosinus() {
  if (values_stack_.empty()) {
    return false;
  }

  double angle = stod(values_stack_.top());
  values_stack_.pop();

  double result = cos(angle);

  values_stack_.push(std::to_string(result));
  return true;
}

bool CalcModel::Tangent() {
  if (values_stack_.empty()) {
    return false;
  }

  double angle = stod(values_stack_.top());
  values_stack_.pop();

  double result = tan(angle);

  values_stack_.push(std::to_string(result));
  return true;
}

bool CalcModel::Atangent() {
  if (values_stack_.empty()) {
    return false;
  }

  double value = stod(values_stack_.top());
  values_stack_.pop();

  double result = atan(value);

  values_stack_.push(std::to_string(result));
  return true;
}

bool CalcModel::Asinus() {
  if (values_stack_.empty()) {
    return false;
  }

  double value = stod(values_stack_.top());
  values_stack_.pop();

  double result = asin(value);

  values_stack_.push(std::to_string(result));
  return true;
}

bool CalcModel::Acosinus() {
  if (values_stack_.empty()) {
    return false;
  }

  double value = stod(values_stack_.top());
  values_stack_.pop();

  double result = acos(value);

  values_stack_.push(std::to_string(result));
  return true;
}

bool CalcModel::Square() {
  if (values_stack_.empty()) {
    return false;
  }

  double value = stod(values_stack_.top());
  values_stack_.pop();

  double result = sqrt(value);

  values_stack_.push(std::to_string(result));
  return true;
}

bool CalcModel::LnFunc() {
  if (values_stack_.empty()) {
    return false;
  }

  double value = stod(values_stack_.top());
  values_stack_.pop();

  double result = log(value);

  values_stack_.push(std::to_string(result));
  return true;
}

bool CalcModel::LogFunc() {
  if (values_stack_.empty()) {
    return false;
  }

  double value = stod(values_stack_.top());
  values_stack_.pop();

  double result = log10(value);

  values_stack_.push(std::to_string(result));
  return true;
}

bool CalcModel::CountFunction() {
  if (values_stack_.empty()) {
    return false;
  }

  std::string token = values_stack_.top();
  std::cout << "CF top: " << values_stack_.top() << "\n";
  values_stack_.pop();
  std::cout << "CF top: " << values_stack_.top() << "\n";

  bool flag = true;

  if (token == "+") {
    flag = Sum();
  } else if (token == "/") {
    flag = Division();
  } else if (token == "*") {
    flag = Multiplication();
  } else if (token == "-") {
    flag = Difference();
  } else if (token == "%") {
    flag = Mod();
  } else if (token == "^") {
    flag = Power();
  } else if (token == "sin") {
    flag = Sinus();
  } else if (token == "cos") {
    flag = Cosinus();
  } else if (token == "tan") {
    flag = Tangent();
  } else if (token == "atan") {
    flag = Atangent();
  } else if (token == "acos") {
    flag = Acosinus();
  } else if (token == "asin") {
    flag = Asinus();
  } else if (token == "sqrt") {
    flag = Square();
  } else if (token == "ln") {
    flag = LnFunc();
  } else if (token == "log") {
    flag = LogFunc();
  }

  if (stod(result_.top()) != floor(stod(result_.top()))) {
    std::string resultString = result_.top();
    size_t i = resultString.length() - 1;

    while (i > 0 && (resultString[i] == '0' || resultString[i] == '.')) {
      if (resultString[i] == '.') {
        i--;
        break;
      }
      i--;
    }

    result_.top() = resultString.substr(0, i + 1);
    std::cout << "res:" << result_.top();
  }

  return flag;
}

int CalcModel::CountChars(const std::string& str, char c) {
  return std::count(str.begin(), str.end(), c);
}

bool CalcModel::Calculate() {
  bool flag = true;

  while (values_stack_.size() > 0) {
    std::cout << "top: " << values_stack_.top() << "\n";
    if (CountChars(values_stack_.top(), ',') > 1 ||
         CountChars(values_stack_.top(), '.') > 1) {
      flag = false;
      break;
    } else if (result_.empty() && !IsDelim(values_stack_.top()[0]) &&
               !IsFunction(values_stack_.top())) {
                std::cout << "kek1: " << values_stack_.top() << "\n";
      result_.push(values_stack_.top());
      values_stack_.pop();
    } else if (IsDelim(values_stack_.top()[0]) ||
               IsFunction(values_stack_.top())) {
      std::cout << "kek2: " << values_stack_.top() << "\n";
      flag = CountFunction();
      if (!flag) break;
    } else {
      std::cout << "kek3: " << values_stack_.top() << "\n";
      std::string value = values_stack_.top();
      values_stack_.pop();
      result_.push(value);
      std::cout << result_.top() ;
    }
    std::cout << "??\n";
    // values_stack_.pop();
    // std::cout << "kek4: " << values_stack_.top() << "\n";
  }

  // result_ = stod(values_stack_.top());
  return flag;
}

bool CalcModel::Unaries(std::string& input, std::string& dest) {
  std::string token, prev_token, copy;
  size_t i = 0, prev_i, input_size = input.size();
  while (i < input_size) {
    
    prev_i = i;
    std::string tmp = input.substr(i);
    GetToken(token, tmp, i);
    if (prev_i == i) break;

    if (token.empty()) {
      return false;
    }

    if ((prev_token.empty() || (IsDelim(prev_token[0]) && prev_token != "(")) &&
            (token == "+" || token == "-")) {
      if (prev_token == "+" && (token == "+"))
        return false;
      else if (prev_token == "+" && token == "-")
        return false;
      else if (prev_token == "-" && token == "+")
        return false;
      else if (prev_token == "-" && token == "-")
        return false;
      else {
        copy += '(';
        copy += '0';
        copy += token[0];
        tmp = input.substr(i);
        GetToken(token, tmp, i);
        if (IsFunction(token)) {
          copy += '1';
          copy += ')';
          copy += '*';
          copy += token;
        } else {
          copy += token;
          copy += ')';
        }
      }
    } else {
      copy += token;
    }

    prev_token = token;
  }
  dest = copy;
  return true;
}

bool CalcModel::ScanRpn(std::string& input) {
  if (input.empty()) {
    std::cerr << "Input string is empty." << std::endl;
    return false;
  }

  if (std::count(input.begin(), input.end(), '(') !=
      std::count(input.begin(), input.end(), ')')) {
    std::cerr << "Mismatched parentheses in the input string." << std::endl;
    return false;
  }

  std::string processedInput;
  std::cout << "input" << input << std::endl;
  if (!Unaries(input, processedInput)) {
    std::cerr << "Failed to process unary operators." << std::endl;
    return false;
  }
  std::cout << "processed: " << processedInput << std::endl;

  if (!Dijkstra(processedInput)) {
    std::cerr << "Failed to convert to RPN." << std::endl;
    return false;
  }

  if (!Calculate()) {
    std::cerr << "Failed to calculate result." << std::endl;
    return false;
  }

  return true;
}

}  // namespace s21

int main() {
  s21::CalcModel calc_model;
  std::string result;
  std::string input = "1+3";
  calc_model.ScanRpn(input);
  std::cout << "result" << calc_model.GetResult();
  return 0;
}
