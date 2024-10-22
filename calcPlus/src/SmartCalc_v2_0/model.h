#ifndef CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_MODEL_H_
#define CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_MODEL_H_

#include <cmath>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>

#define MAXSIZE 255  // Максимально разрешенный размер для ввода пользователем.

namespace s21 {

class Model {
 public:
  inline Model() noexcept { data = 0; };

  void resultModel(std::string input, double x) noexcept;

  bool checkInputCorrect(const std::string input) noexcept;

  inline double getData() const noexcept { return data; }

  bool validator(std::string) const noexcept;

 private:
  double data; /**< Результат вычислений. */

  std::string convertLexToSym(std::string input, double x) noexcept;

  std::string reverseNotation(std::string input) noexcept;

  inline bool isOperator(char ch) const noexcept {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ||
           ch == '%';
  }
  inline bool isUnaryOperator(char ch) const noexcept {
    return ch == 's' || ch == 'c' || ch == 't' || ch == 'S' || ch == 'C' ||
           ch == 'T' || ch == 'q' || ch == 'g' || ch == 'l';
  }
};
}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_MODEL_H_
