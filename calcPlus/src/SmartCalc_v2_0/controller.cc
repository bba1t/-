#include "controller.h"

double s21::Controller::resultController(std::string input,
                                         double x) const noexcept {
  model->resultModel(input, x);
  return model->getData();
}

bool s21::Controller::checkInputCorrect(
    const std::string input) const noexcept {
  return model->checkInputCorrect(input);
}

bool s21::Controller::validatorController(std::string input) const noexcept {
  // Вызываем метод валидации модели для входной строки и возвращаем результат
  return model->validator(input);
}
