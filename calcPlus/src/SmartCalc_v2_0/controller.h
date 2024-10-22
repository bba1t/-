#ifndef CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_CONTROLLER_H_

#include <string>

#include "model.h"

namespace s21 {

class Controller {
 public:
  inline Controller(s21::Model *m) : model(m){};

  double resultController(std::string input, double x) const noexcept;

  bool checkInputCorrect(const std::string input) const noexcept;

  bool validatorController(std::string input) const noexcept;

 private:
  s21::Model *model;  ///< Указатель на объект модели.
};
}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_CONTROLLER_H_
