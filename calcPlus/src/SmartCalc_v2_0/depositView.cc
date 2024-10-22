#include "depositView.h"

#include "depositModel.h"
#include "ui_deposit.h"

s21::Deposit::Deposit(QWidget *parent) noexcept
    : QMainWindow(parent), ui(new Ui::Deposit) {
  ui->setupUi(this);
}

s21::Deposit::~Deposit() { delete ui; }

void s21::Deposit::on_flag_clicked(bool checked) noexcept {
  if (checked)
    flag = 1;
  else
    flag = 0;
}

void s21::Deposit::on_calculate_clicked() noexcept {
  // Проверка правильного ввода данных
  if (validator(ui->input_deposit->text().toStdString()) &&
      validator(ui->input_period->text().toStdString()) &&
      validator(ui->input_rate->text().toStdString()) &&
      validator(ui->input_replenishment->text().toStdString()) &&
      validator(ui->input_withdraw->text().toStdString()) &&
      validator(ui->input_taxrate->text().toStdString())) {
    QString str_deposit = ui->input_deposit->text();
    double deposit_amount = str_deposit.toDouble();
    QString str_period = ui->input_period->text();
    double period = str_period.toDouble();
    QString str_rate = ui->input_rate->text();
    double rate = str_rate.toDouble();
    QString str_replenishment = ui->input_replenishment->text();
    double replenishment = str_replenishment.toDouble();
    QString str_withdrawals = ui->input_withdraw->text();
    double withdrawals = str_withdrawals.toDouble();
    QString str_taxrate = ui->input_taxrate->text();
    double tax_rate = str_taxrate.toDouble();

    double accrueds = 0;
    double depositEnd = 0;
    double tax_amount = 0;

    depositCalculator.deposit(deposit_amount, period, rate, tax_rate, accrueds,
                              depositEnd, tax_amount, flag, replenishment,
                              withdrawals, periodicity);

    QString p_outputCharges = QString::number(accrueds, 'g', 6);
    QString p_depositEnd = QString::number(depositEnd, 'g', 6);
    QString p_taxAmount = QString::number(tax_amount, 'g', 6);

    ui->input_percent->setText(p_outputCharges);
    ui->input_depositEnd->setText(p_depositEnd);
    ui->input_tax->setText(p_taxAmount);
  } else {
    ui->input_tax->setText("ERROR!");
    ui->input_percent->setText("ERROR!");
    ui->input_depositEnd->setText("ERROR!");
  }
}

/**
 * @brief Обработчик события выбора опции из выпадающего списка пополнения.
 *
 * Устанавливает значение переменной periodicity в зависимости от выбранной
 * опции.
 *
 * @param index Индекс выбранной опции в выпадающем списке.
 *
 * @note Функция вызывается при выборе опции из выпадающего списка пополнения в
 * пользовательском интерфейсе.
 *
 * @return void
 */
void s21::Deposit::on_dropdown_replemishment_activated(int index) noexcept {
  if (index == 0) periodicity = 0;
  if (index == 1) periodicity = 1;
  if (index == 2) periodicity = 3;
  if (index == 3) periodicity = 6;
  if (index == 4) periodicity = 12;
}

void s21::Deposit::on_dropdown_withdraw_activated(int index) noexcept {
  if (index == 0) periodicity = 0;
  if (index == 1) periodicity = 1;
  if (index == 2) periodicity = 3;
  if (index == 3) periodicity = 6;
  if (index == 4) periodicity = 12;
}

bool s21::Deposit::validator(std::string input) const noexcept {
  // Проверка, что все символы являются цифрами или точкой
  for (size_t i = 0; i < input.size(); ++i) {
    if (input[i] != '.' && !(std::isdigit(input[i]))) {
      return false;
    }
  }

  // Проверка, что строка не начинается или не заканчивается точкой
  if (input[0] == '.' || input[input.size() - 1] == '.') {
    return false;
  }

  // Проверка, что строка не содержит подряд идущих точек
  for (size_t i = 0; i < input.size(); ++i) {
    if (input[i] == '.' && input[i + 1] == '.') {
      return false;
    }
  }

  // Входная строка представляет корректное число
  return true;
}
