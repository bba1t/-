#ifndef CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_DEPOSITMODEL_H_
#define CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_DEPOSITMODEL_H_

#include <cmath>

namespace s21 {
class DepositCalculator {
 public:
  void deposit(double deposit_amount, double period, double rate,
               double tax_rate, double& accrued, double& deposit_end,
               double& tax_amount, int capital_flag, double replenishment,
               double withdrawals, double periodicity) noexcept;

  void check_periodicity(double period, double periodicity,
                         int& count) noexcept;

  void capital(double period, double& deposit_end, double& accrueds,
               double replenishment, double withdrawals, double rate,
               double& tmp, double& tmp_1, int& count) noexcept;

  void without_capital(double period, double& deposit_end, double& accrueds,
                       double replenishment, double withdrawals, double rate,
                       double& tmp, double& tmp_1, int& count) noexcept;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_DEPOSITMODEL_H_
