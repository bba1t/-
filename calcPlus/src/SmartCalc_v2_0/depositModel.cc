#include "depositModel.h"

void s21::DepositCalculator::deposit(double deposit_amount, double period,
                                     double rate, double tax_rate,
                                     double &accrued, double &deposit_end,
                                     double &tax_amount, int capital_flag,
                                     double replenishment, double withdrawals,
                                     double periodicity) noexcept {
  int count = 0;
  double tmp = 0.;
  double tmp_1 = 0.;

  // Рассчет для с капитализацией и без пополнения и снятия
  if (capital_flag == 1 && replenishment == 0 && withdrawals == 0 &&
      periodicity == 0) {
    accrued = deposit_amount * rate * (period * 30.44 / 365.25) / 100;
    deposit_end = deposit_amount + accrued;
  }
  if (capital_flag == 0 && replenishment == 0 && withdrawals == 0 &&
      periodicity == 0) {
    accrued = deposit_amount * rate * (period * 30.44 / 365.25) / 100;
    deposit_end = deposit_amount;
  }

  // Рассчет для с капитализацией и пополнением/снятием с периодичностью
  if (capital_flag == 1 && replenishment != 0 && withdrawals == 0 &&
      periodicity != 0) {
    deposit_end = deposit_amount;

    check_periodicity(period, periodicity, count);

    capital(period, deposit_end, accrued, replenishment, withdrawals, rate, tmp,
            tmp_1, count);
  }
  if (capital_flag == 0 && replenishment != 0 && withdrawals == 0 &&
      periodicity != 0) {
    deposit_end = deposit_amount;

    check_periodicity(period, periodicity, count);

    without_capital(period, deposit_end, accrued, replenishment, withdrawals,
                    rate, tmp, tmp_1, count);
  }

  // Рассчет для с капитализацией и снятием с периодичностью
  if (capital_flag == 1 && replenishment == 0 && withdrawals != 0 &&
      periodicity != 0) {
    deposit_end = deposit_amount;
    check_periodicity(period, periodicity, count);

    capital(period, deposit_end, accrued, replenishment, withdrawals, rate, tmp,
            tmp_1, count);
  } else if (capital_flag == 0 && replenishment == 0 && withdrawals != 0 &&
             periodicity != 0) {
    deposit_end = deposit_amount;

    check_periodicity(period, periodicity, count);

    without_capital(period, deposit_end, accrued, replenishment, withdrawals,
                    rate, tmp, tmp_1, count);
  }

  // Рассчет налога
  if (tax_rate > 0) tax_amount = accrued * tax_rate / 100;
}

/**
 * @brief Проверяет периодичность начисления процентов и вычисляет коэффициент
 * начисления.
 *
 * @param period Период вклада в месяцах.
 * @param periodicity Периодичность начисления процентов (12, 6, 3 или 1 месяц).
 * @param count Количество периодов начисления процентов.
 *
 * @return void
 */
void s21::DepositCalculator::check_periodicity(double period,
                                               double periodicity,
                                               int &count) noexcept {
  if (periodicity == 12) count = roundl(period / 12) * 10 / 100 * 10;

  if (periodicity == 6) count = roundl(period / 6) * 10 / 100 * 10;

  if (periodicity == 3) count = roundl(period / 3) * 10 / 100 * 10;

  if (periodicity == 1) count = roundl(period / 1) * 10 / 100 * 10;
}

void s21::DepositCalculator::capital(double period, double &deposit_end,
                                     double &accrued, double replenishment,
                                     double withdrawals, double rate,
                                     double &tmp, double &tmp_1,
                                     int &count) noexcept {
  if (replenishment != 0 && withdrawals == 0) {
    for (int j = 0; j < period; ++j) {
      if ((count == 1 || count == 2) && j == 0) deposit_end += replenishment;

      if ((count == 2 && j == 0) || (count == 2 && j == 3))
        deposit_end += replenishment;

      if (count == 6 && j <= 6) deposit_end += replenishment;

      tmp = deposit_end * (1 + rate / 100);
      tmp_1 = tmp * count + deposit_end;
      accrued += tmp;
      deposit_end += tmp;
    }
  }

  if (replenishment == 0 && withdrawals != 0) {
    for (int j = 0; j < period; ++j) {
      if ((count == 1 || count == 2) && j == 0) deposit_end -= withdrawals;

      if ((count == 2 && j == 0) || (count == 2 && j == 3))
        deposit_end -= withdrawals;

      if (count == 6 && j <= 6) deposit_end -= withdrawals;

      tmp = deposit_end * (1 + rate / 100);
      tmp_1 = tmp * count + deposit_end;
      accrued += tmp;
      deposit_end += tmp;
    }
  }
}

void s21::DepositCalculator::without_capital(double period, double &deposit_end,
                                             double &accrued,
                                             double replenishment,
                                             double withdrawals, double rate,
                                             double &tmp, double &tmp_1,
                                             int &count) noexcept {
  if (replenishment != 0 && withdrawals == 0) {
    for (int j = 0; j < period; ++j) {
      if ((count == 1 || count == 2) && j == 0) deposit_end += replenishment;

      if ((count == 2 && j == 0) || (count == 2 && j == 3))
        deposit_end += replenishment;

      if (count == 6 && j <= 6) deposit_end += replenishment;

      tmp = deposit_end * (1 + rate / 100);
      tmp_1 = tmp * count + deposit_end;
      accrued += tmp;
    }
  }

  if (replenishment == 0 && withdrawals != 0) {
    for (int j = 0; j < period; ++j) {
      if ((count == 1 || count == 2) && j == 0) deposit_end -= withdrawals;

      if ((count == 2 && j == 0) || (count == 2 && j == 3))
        deposit_end -= withdrawals;

      if (count == 6 && j <= 6) deposit_end -= withdrawals;

      tmp = deposit_end * (1 + rate / 100);
      tmp_1 = tmp * count + deposit_end;
      accrued += tmp;
    }
  }
}
