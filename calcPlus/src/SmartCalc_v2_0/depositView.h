#ifndef CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_DEPOSITVIEW_H_
#define CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_DEPOSITVIEW_H_

#include <QMainWindow>

#include "depositModel.h"

namespace Ui {
class Deposit;
}

namespace s21 {
class Deposit : public QMainWindow {
  Q_OBJECT

 public:
  explicit Deposit(QWidget* parent = nullptr) noexcept;

  ~Deposit();

  int flag = 0; /**< Флаг для определения типа депозита. */
  double periodicity = 0.; /**< Периодичность пополнения/снятия средств. */

 private slots:
  void on_calculate_clicked() noexcept;

  void on_flag_clicked(bool checked) noexcept;

  void on_dropdown_replemishment_activated(int index) noexcept;

  void on_dropdown_withdraw_activated(int index) noexcept;

 private:
  Ui::Deposit* ui; /**< Указатель на объект пользовательского интерфейса. */
  s21::DepositCalculator depositCalculator; /**< Объект для расчета депозита. */

  bool validator(std::string input) const noexcept;
};
}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_0_1_SMARTCALC_V2_0_DEPOSITVIEW_H_
