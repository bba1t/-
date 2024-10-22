#ifndef CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_CREDITMODEL_H_
#define CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_CREDITMODEL_H_

#include <cmath>
#include <string>
#include <vector>

namespace s21 {
class CreditModel {
 public:
  enum LoanType { ANNUITY, DIFFERENTIATED };

  struct LoanInfo {
    double amount; /**< Сумма кредита. */
    double rate;   /**< Процентная ставка. */
    int term;      /**< Срок кредита в месяцах. */
    LoanType type; /**< Тип кредита (аннуитетный или дифференцированный). */
  };

  struct LoanResult {
    int err;             /**< Код ошибки (0 - нет ошибки). */
    std::string message; /**< Сообщение об ошибке (если есть). */
    std::vector<double> monthly_payments; /**< Массив ежемесячных платежей. */
    double overpayment; /**< Переплата по кредиту (проценты). */
    double total; /**< Общая сумма выплаты по кредиту. */
  };

  static LoanResult checkLoanType(LoanInfo loan) noexcept;

  static LoanResult annuity(LoanInfo loan) noexcept;

  static LoanResult differentiated(LoanInfo loan) noexcept;

  static std::string initLoan(LoanInfo loan) noexcept;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_CREDITMODEL_H_
