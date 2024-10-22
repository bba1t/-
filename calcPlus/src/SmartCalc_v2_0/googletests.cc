#include <gtest/gtest.h>

#include "controller.h"
#include "creditModel.h"
#include "depositModel.h"
#include "model.h"

using namespace s21;

TEST(ControllerTest, Test1) {
  Model model;
  Controller controller(&model);
  controller.resultController("-11+23*(2-2)", 0);
  double expected_result = -11.0;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ControllerTest, Test2) {
  Model model;
  Controller controller(&model);
  controller.checkInputCorrect("2^3");
  controller.resultController("2^3", 0);
  double expected_result = 8;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ControllerTest, Test3) {
  Model model;
  Controller controller(&model);
  controller.resultController("2345/6.55/3/2*(9-100+(-200))", 0);
  double expected_result = -17363.7404580;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ResultModelTest, Test1) {
  Model model;
  model.resultModel("2*2+1+1+1*2^2*2+2^3+1+1", 0);
  double expected_result = 24.;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ResultModelTest, Test2) {
  Model model;
  model.resultModel("cos(12.4)", 0);
  double expected_result = 0.9861923;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ResultModelTest, Test3) {
  Model model;
  model.resultModel("sin(123-100*8^5%2/10+904.25)", 0);
  double expected_result = 0.0507759;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ResultModelTest, Test4) {
  Model model;
  model.resultModel("acos(1-0.25)", 0);
  double expected_result = 0.7227342;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ResultModelTest, Test5) {
  Model model;
  model.resultModel("asin(0.69)-asin(0.69)", 0);
  double expected_result = 0;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ResultModelTest, Test6) {
  Model model;
  model.resultModel("atan(6+77/6*(7-8-(9%6-10)+100))", 0);
  double expected_result = 1.5700644;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ResultModelTest, Test7) {
  Model model;
  model.resultModel("sqrt(77-8-sqrt(88))+sqrt(2.34)", 0);
  double expected_result = 9.2510508;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ResultModelTest, Test8) {
  Model model;
  model.resultModel("ln(345.6+567.8-567.3)", 0);
  double expected_result = 5.8467278;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ResultModelTest, UnaryPlus) {
  Model model;
  model.resultModel("+30+2*(+10-1)", 0);
  double expected_result = 48.;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ResultModelTest, Test9) {
  Model model;
  model.resultModel("28*37-123", 0);
  double expected_result = 913;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ResultModelTest, Test10) {
  Model model;
  model.resultModel("-28*37-123", 0);
  double expected_result = -1159;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ResultModelTest, X) {
  Model model;
  model.resultModel("15%x", 3);
  double expected_result = 0;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ResultModelTest, TanX) {
  Model model;
  model.resultModel("tan(tan(x))", 5);
  double expected_result = -0.2435748;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

TEST(ResultModelTest, log) {
  Model model;
  model.resultModel("log5", 0);
  double expected_result = 0.69897;
  EXPECT_NEAR(expected_result, model.getData(), 1e-7);
}

// Тестирование функции initLoan()
TEST(CreditModel, InitLoanValid) {
  s21::CreditModel::LoanInfo validLoan = {10000.0, 10.0, 24,
                                          s21::CreditModel::ANNUITY};
  ASSERT_EQ(s21::CreditModel::initLoan(validLoan), "");
}

TEST(CreditModel, InitLoanInvalidRate) {
  s21::CreditModel::LoanInfo invalidLoan = {10000.0, -10.0, 24,
                                            s21::CreditModel::ANNUITY};
  ASSERT_EQ(s21::CreditModel::initLoan(invalidLoan),
            "[2] Некорректная процентная ставка!");
}

// Тестирование функции checkLoanType()
TEST(CreditModel, CheckLoanTypeAnnuity) {
  s21::CreditModel::LoanInfo loan = {10000.0, 10.0, 24,
                                     s21::CreditModel::ANNUITY};
  s21::CreditModel::LoanResult result = s21::CreditModel::checkLoanType(loan);
  ASSERT_EQ(result.message, "");
}

TEST(CreditModel, CheckLoanTypeDifferentiated) {
  s21::CreditModel::LoanInfo loan = {10000.0, 10.0, 24,
                                     s21::CreditModel::DIFFERENTIATED};
  s21::CreditModel::LoanResult result = s21::CreditModel::checkLoanType(loan);
  ASSERT_EQ(result.message, "");
}

// Тестирование функции check_periodicity()
TEST(DepositCalculator, CheckPeriodicity12) {
  s21::DepositCalculator depositCalculator;
  int count = 0;

  depositCalculator.check_periodicity(24, 12, count);
  ASSERT_EQ(count, 2);
}

TEST(DepositCalculator, CheckPeriodicity6) {
  s21::DepositCalculator depositCalculator;
  int count = 0;

  depositCalculator.check_periodicity(24, 6, count);
  ASSERT_EQ(count, 4);
}

TEST(DepositCalculator, CheckPeriodicity3) {
  s21::DepositCalculator depositCalculator;
  int count = 0;

  depositCalculator.check_periodicity(24, 3, count);
  ASSERT_EQ(count, 8);
}

TEST(DepositCalculator, CheckPeriodicity1) {
  s21::DepositCalculator depositCalculator;
  int count = 0;

  depositCalculator.check_periodicity(24, 1, count);
  ASSERT_EQ(count, 24);
}

// Тестирование функции capital()
TEST(DepositCalculator, CapitalCalculation) {
  s21::DepositCalculator depositCalculator;
  double deposit_amount = 1000;
  double period = 6;
  double rate = 2;
  double tax_rate = 13;
  double deposit_end = 0;
  double accrued = 0;
  double tax_amount = 0;
  double capital_flag = 0;
  double replenishment = 0;
  double withdrawals = 0;
  double periodicity = 0;
  depositCalculator.deposit(deposit_amount, period, rate, tax_rate, accrued,
                            deposit_end, tax_amount, capital_flag,
                            replenishment, withdrawals, periodicity);

  ASSERT_EQ(deposit_end, 1000);
}

TEST(DepositCalculator, WithoutCapitalCalculation) {
  s21::DepositCalculator depositCalculator;
  double deposit_amount = 1000;
  double period = 6;
  double rate = 2;
  double tax_rate = 13;
  double deposit_end = 0;
  double accrued = 0;
  double tax_amount = 0;
  double capital_flag = 1;
  double replenishment = 0;
  double withdrawals = 0;
  double periodicity = 0;
  depositCalculator.deposit(deposit_amount, period, rate, tax_rate, accrued,
                            deposit_end, tax_amount, capital_flag,
                            replenishment, withdrawals, periodicity);

  ASSERT_NEAR(deposit_end, 1010, 1e-3);
}

TEST(DepositCalculator, WithoutCapitalReplenishment) {
  s21::DepositCalculator depositCalculator;
  double period = 24;
  double deposit_end = 10000.0;
  double accrued = 0.0;
  double replenishment = 100.0;
  double withdrawals = 0.0;
  double rate = 10.0;
  double tmp = 0.0;
  double tmp_1 = 0.0;
  int count = 20;

  depositCalculator.without_capital(period, deposit_end, accrued, replenishment,
                                    withdrawals, rate, tmp, tmp_1, count);

  ASSERT_NEAR(deposit_end, 10000, 1e-7);

  ASSERT_NEAR(accrued, 264000, 1e-7);
}

TEST(DepositCalculator, WithoutCapitalWithdrawals) {
  s21::DepositCalculator depositCalculator;
  double period = 24;
  double deposit_end = 10000.0;
  double accrued = 0.0;
  double replenishment = 0.0;
  double withdrawals = 100.0;
  double rate = 10.0;
  double tmp = 0.0;
  double tmp_1 = 0.0;
  int count = 20;

  depositCalculator.without_capital(period, deposit_end, accrued, replenishment,
                                    withdrawals, rate, tmp, tmp_1, count);

  ASSERT_NEAR(deposit_end, 10000, 0.01);

  ASSERT_NEAR(accrued, 264000, 0.01);
}

TEST(DepositCalculator, CapitalReplenishment) {
  s21::DepositCalculator depositCalculator;
  double period = 24;
  double deposit_end = 10000.0;
  double accrued = 0.0;
  double replenishment = 100.0;
  double withdrawals = 0.0;
  double rate = 10.0;
  double tmp = 0.0;
  double tmp_1 = 0.0;
  int count = 20;

  depositCalculator.capital(period, deposit_end, accrued, replenishment,
                            withdrawals, rate, tmp, tmp_1, count);

  ASSERT_NEAR(deposit_end, 541081983772.72626, 1e-7);
}

TEST(DepositCalculator, CapitalWithdrawals) {
  s21::DepositCalculator depositCalculator;
  double period = 24;
  double deposit_end = 10000.0;
  double accrued = 0.0;
  double replenishment = 0.0;
  double withdrawals = 100.0;
  double rate = 10.0;
  double tmp = 0.0;
  double tmp_1 = 0.0;
  int count = 20;

  depositCalculator.capital(period, deposit_end, accrued, replenishment,
                            withdrawals, rate, tmp, tmp_1, count);

  ASSERT_NEAR(deposit_end, 541081983772.72626, 0.01);
}

TEST(DepositCalculator, CapitalNoReplenishmentNoWithdrawalsNoTax) {
  s21::DepositCalculator depositCalculator;
  double deposit_amount = 10000.0;
  double period = 12.0;
  double rate = 10.0;
  double tax_rate = 0.0;
  double accrued = 0.0;
  double deposit_end = 0.0;
  double tax_amount = 0.0;
  int capital_flag = 1;
  double replenishment = 0.0;
  double withdrawals = 0.0;
  double periodicity = 0.0;

  depositCalculator.deposit(deposit_amount, period, rate, tax_rate, accrued,
                            deposit_end, tax_amount, capital_flag,
                            replenishment, withdrawals, periodicity);

  ASSERT_NEAR(accrued, 1000.0821355236139, 0.01);
  ASSERT_NEAR(deposit_end, 11000.082135523615, 0.01);
  ASSERT_NEAR(tax_amount, 0.0, 0.01);
}

TEST(DepositCalculator, CapitalReplenishmentWithdrawalsTax) {
  s21::DepositCalculator depositCalculator;
  double deposit_amount = 10000.0;
  double period = 12.0;
  double rate = 10.0;
  double tax_rate = 15.0;
  double accrued = 0.0;
  double deposit_end = 0.0;
  double tax_amount = 0.0;
  int capital_flag = 1;
  double replenishment = 500.0;
  double withdrawals = 200.0;
  double periodicity = 1.0;

  depositCalculator.deposit(deposit_amount, period, rate, tax_rate, accrued,
                            deposit_end, tax_amount, capital_flag,
                            replenishment, withdrawals, periodicity);

  ASSERT_NEAR(accrued, 0, 0.01);
  ASSERT_NEAR(deposit_end, 0, 0.01);
  ASSERT_NEAR(tax_amount, 0, 0.01);
}

TEST(Validator, Test1) {
  Model model;
  Controller controller(&model);
  ASSERT_EQ(controller.validatorController("-11+23*(2-2)"), false);
}

TEST(Validator, Test2) {
  Model model;
  Controller controller(&model);
  ASSERT_EQ(controller.validatorController("2..2113"), false);
}

TEST(Validator, Test3) {
  Model model;
  Controller controller(&model);
  ASSERT_EQ(controller.validatorController(".124141"), false);
}

TEST(Validator, Test4) {
  Model model;
  Controller controller(&model);
  ASSERT_EQ(controller.validatorController("124141."), false);
}

TEST(Validator, Test5) {
  Model model;
  Controller controller(&model);
  ASSERT_EQ(controller.validatorController("124141qwfqfqf"), false);
}

TEST(Validator, Test6) {
  Model model;
  Controller controller(&model);
  ASSERT_EQ(controller.validatorController("232323"), true);
}

TEST(Validator, Test7) {
  Model model;
  Controller controller(&model);
  ASSERT_EQ(controller.validatorController("23.2323"), true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
