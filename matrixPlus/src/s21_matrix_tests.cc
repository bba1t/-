#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(EqMatrix, True) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(3, 3);
  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(EqMatrix, False) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(2, 2);
  ASSERT_FALSE(matrix_a == matrix_b);
}

TEST(SumMatrix, plus2) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  a.SumMatrix(b);
  EXPECT_DOUBLE_EQ(a(1, 1), 3.3);
}

TEST(SumMatrix, plus3) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);
  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;
  matrix_a(1, 0) = -69.3;
  matrix_a(1, 1) = 0;
  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;
  result(0, 0) = -75;
  result(0, 1) = 0.56;
  result(1, 0) = -69.6;
  result(1, 1) = 2;
  matrix_a.SumMatrix(matrix_b);
  ASSERT_TRUE(matrix_a == result);
}

TEST(SubMatrix, minus1) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);
  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;
  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;
  result(0, 0) = 10;
  result(0, 1) = 2;
  result(1, 0) = -3;
  result(1, 1) = -2;
  matrix_a.SubMatrix(matrix_b);
  ASSERT_TRUE(matrix_a == result);
}

TEST(SubMatrix, minus2) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  a.SubMatrix(b);
  EXPECT_DOUBLE_EQ(a(1, 1), -1.1);
}

TEST(MulNumber, number1) {
  S21Matrix matrix_a(2, 2);
  S21Matrix result(2, 2);
  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;
  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;
  matrix_a.MulNumber(10);
  ASSERT_TRUE(matrix_a == result);
}

TEST(MulNumber, number2) {
  S21Matrix a(3, 2);
  a(1, 1) = 1.1;
  S21Matrix result = a * 2;
  EXPECT_DOUBLE_EQ(result(1, 1), 2.2);
}

TEST(MulNumber, number3) {
  S21Matrix a(3, 2);
  a(1, 1) = 1.1;
  a *= 2;
  EXPECT_DOUBLE_EQ(a(1, 1), 2.2);
}

TEST(MulNumber, number4) {
  S21Matrix a(3, 2);
  a(1, 1) = 1.1;
  a.MulNumber(2);
  EXPECT_DOUBLE_EQ(a(1, 1), 2.2);
}

TEST(MulNumber, number5) {
  S21Matrix a(3, 2);
  a.MulNumber(NAN);
  EXPECT_EQ(std::isnan(a(1, 1)), 1);
  EXPECT_EQ(std::isnan(a(2, 1)), 1);
  EXPECT_EQ(std::isnan(a(1, 0)), 1);
}

TEST(MulMatrix, mul1) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);
  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;
  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;
  result(0, 0) = -28;
  result(0, 1) = 4;
  result(1, 0) = 46.2;
  result(1, 1) = 0;
  matrix_a.MulMatrix(matrix_b);
  ASSERT_TRUE(matrix_a == result);
}

TEST(MulMatrix, mul3) {
  S21Matrix a(3, 2);
  S21Matrix b(2, 3);
  S21Matrix res(3, 3);
  a(0, 0) = 0;
  a(0, 1) = 1;
  a(1, 0) = 3;
  a(1, 1) = 4;
  a(2, 0) = 6;
  a(2, 1) = 7;
  b(0, 0) = 9;
  b(0, 1) = 8;
  b(0, 2) = 7;
  b(1, 0) = 6;
  b(1, 1) = 5;
  b(1, 2) = 4;
  a.MulMatrix(b);
  res(0, 0) = 6;
  res(0, 1) = 5;
  res(0, 2) = 4;
  res(1, 0) = 51;
  res(1, 1) = 44;
  res(1, 2) = 37;
  res(2, 0) = 96;
  res(2, 1) = 83;
  res(2, 2) = 70;
  ASSERT_TRUE(a == res);
}

TEST(Determinant, determinant1) {
  S21Matrix basic(4, 4);
  basic(0, 0) = 9;
  basic(0, 1) = 2;
  basic(0, 2) = 2;
  basic(0, 3) = 4;
  basic(1, 0) = 3;
  basic(1, 1) = 4;
  basic(1, 2) = 4;
  basic(1, 3) = 4;
  basic(2, 0) = 4;
  basic(2, 1) = 4;
  basic(2, 2) = 9;
  basic(2, 3) = 9;
  basic(3, 0) = 1;
  basic(3, 1) = 1;
  basic(3, 2) = 5;
  basic(3, 3) = 1;
  EXPECT_DOUBLE_EQ(basic.Determinant(), -578);
}

TEST(Determinant, determinant2) {
  S21Matrix basic(1, 1);
  basic(0, 0) = 10;
  EXPECT_DOUBLE_EQ(basic.Determinant(), 10);
}

TEST(Determinant, determinant3) {
  S21Matrix basic(2, 2);
  basic(0, 0) = 1.1;
  basic(0, 1) = 3.5;

  basic(1, 0) = -2;
  basic(1, 1) = 4;
  EXPECT_DOUBLE_EQ(basic.Determinant(), 11.4);
}

TEST(Transpose, test1) {
  S21Matrix matrix_a(4, 3);
  S21Matrix result(3, 4);
  matrix_a(0, 0) = 7;
  matrix_a(0, 1) = -98;
  matrix_a(0, 2) = 0.5;
  matrix_a(1, 0) = 0;
  matrix_a(1, 1) = 5.4;
  matrix_a(1, 2) = 32;
  matrix_a(2, 0) = 3.12;
  matrix_a(2, 1) = 2323;
  matrix_a(2, 2) = 23;
  matrix_a(3, 0) = -78;
  matrix_a(3, 1) = 476.4;
  matrix_a(3, 2) = 21;
  result(0, 0) = 7;
  result(0, 1) = 0;
  result(0, 2) = 3.12;
  result(0, 3) = -78;
  result(1, 0) = -98;
  result(1, 1) = 5.4;
  result(1, 2) = 2323;
  result(1, 3) = 476.4;
  result(2, 0) = 0.5;
  result(2, 1) = 32;
  result(2, 2) = 23;
  result(2, 3) = 21;
  S21Matrix res = matrix_a.Transpose();
  ASSERT_TRUE(res == result);
}

TEST(Transpose, test2) {
  S21Matrix result(2, 2);
  result(0, 0) = 1;
  result(0, 1) = 2;
  result(1, 0) = 4;
  result(1, 1) = 3;
  result = result.Transpose();
  EXPECT_EQ(result(0, 0), 1);
  EXPECT_EQ(result(0, 1), 4);
  EXPECT_EQ(result(1, 0), 2);
  EXPECT_EQ(result(1, 1), 3);
}

TEST(Complements, test1) {
  S21Matrix a(3, 3);
  S21Matrix res(3, 3);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 3;
  a(1, 0) = 0;
  a(1, 1) = 4;
  a(1, 2) = 2;
  a(2, 0) = 5;
  a(2, 1) = 2;
  a(2, 2) = 1;
  a = a.CalcComplements();
  res(0, 0) = 0;
  res(0, 1) = 10;
  res(0, 2) = -20;
  res(1, 0) = 4;
  res(1, 1) = -14;
  res(1, 2) = 8;
  res(2, 0) = -8;
  res(2, 1) = -2;
  res(2, 2) = 4;
  ASSERT_TRUE(a == res);
}

TEST(Complements, test2) {
  S21Matrix a(3, 3);
  S21Matrix res(3, 3);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 3;
  a(1, 0) = 0;
  a(1, 1) = 4;
  a(1, 2) = 2;
  a(2, 0) = 5;
  a(2, 1) = 2;
  a(2, 2) = 1;
  a = a.CalcComplements();
  res(0, 0) = 0;
  res(0, 1) = 10;
  res(0, 2) = -20;
  res(1, 0) = 4;
  res(1, 1) = -14;
  res(1, 2) = 8;
  res(2, 0) = -8;
  res(2, 1) = -2;
  res(2, 2) = 4;
  ASSERT_TRUE(a == res);
}

TEST(Complements, test4) {
  S21Matrix a(4, 4);
  S21Matrix res(4, 4);
  a(0, 0) = 8;
  a(0, 1) = 4;
  a(0, 2) = 6;
  a(0, 3) = 2;
  a(1, 0) = 4;
  a(1, 1) = 7;
  a(1, 2) = 10;
  a(1, 3) = 16;
  a(2, 0) = 42;
  a(2, 1) = 7;
  a(2, 2) = 9;
  a(2, 3) = 47;
  a(3, 0) = 5;
  a(3, 1) = 6;
  a(3, 2) = 20;
  a(3, 3) = 4;
  a = a.CalcComplements();
  res(0, 0) = -2412;
  res(0, 1) = -9774;
  res(0, 2) = 2925;
  res(0, 3) = 3051;
  res(1, 0) = 1920;
  res(1, 1) = -5240;
  res(1, 2) = 1330;
  res(1, 3) = -1190;
  res(2, 0) = -552;
  res(2, 1) = 1796;
  res(2, 2) = -310;
  res(2, 3) = -454;
  res(3, 0) = 12;
  res(3, 1) = 4744;
  res(3, 2) = -3140;
  res(3, 3) = -116;
  ASSERT_TRUE(a == res);
}

TEST(Complements, test5) {
  S21Matrix a(1, 1);
  S21Matrix res(1, 1);
  a(0, 0) = 9;
  a = a.CalcComplements();
  a = a;
  res(0, 0) = 1;
  ASSERT_TRUE(a == res);
}

TEST(Inverse, inverse2) {
  S21Matrix basic(3, 3);
  basic(0, 0) = 4;
  basic(0, 1) = -2;
  basic(0, 2) = 1;
  basic(1, 0) = 1;
  basic(1, 1) = 6;
  basic(1, 2) = -2;
  basic(2, 0) = 1;
  basic(2, 1) = 0;
  basic(2, 2) = 0;
  basic = basic.InverseMatrix();
  EXPECT_EQ(basic(0, 1), 0);
  EXPECT_EQ(basic(0, 2), 1);
  EXPECT_EQ(basic(1, 0), 1);
  EXPECT_EQ(basic(2, 0), 3);
  EXPECT_EQ(basic(2, 1), 1);
  EXPECT_EQ(basic(2, 2), -13);
}

TEST(Inverse, inverse3) {
  S21Matrix basic(3, 3);
  basic(0, 0) = 2;
  basic(0, 1) = 2;
  basic(0, 2) = 123;
  basic(1, 0) = 12;
  basic(1, 1) = 6;
  basic(1, 2) = 5;
  basic(2, 0) = 1;
  basic(2, 1) = 2;
  basic(2, 2) = 8;
  basic = basic.InverseMatrix();
  EXPECT_DOUBLE_EQ(basic(0, 1), 0.10910815939278938);
  EXPECT_DOUBLE_EQ(basic(0, 2), -0.34535104364326374);
  EXPECT_DOUBLE_EQ(basic(1, 0), -0.043168880455407968);
  EXPECT_DOUBLE_EQ(basic(2, 0), 0.0085388994307400382);
  EXPECT_DOUBLE_EQ(basic(2, 1), -0.00094876660341555979);
  EXPECT_DOUBLE_EQ(basic(2, 2), -0.0056925996204933585);
}

TEST(OperatorPlus, plus_1) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);
  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;
  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;
  result(0, 0) = -4;
  result(0, 1) = 2;
  result(1, 0) = -9;
  result(1, 1) = 2;
  ASSERT_TRUE((matrix_a + matrix_b) == result);
}

TEST(OperatorMinus, minus1) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);
  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;
  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;
  result(0, 0) = 10;
  result(0, 1) = 2;
  result(1, 0) = -3;
  result(1, 1) = -2;
  ASSERT_TRUE((matrix_a - matrix_b) == result);
}

TEST(OperatorMinus, minus2) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  S21Matrix result = a - b;
  EXPECT_DOUBLE_EQ(result(1, 1), -1.1);
}

TEST(OperatorMulMatrix, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;
  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;
  result(0, 0) = -28;
  result(0, 1) = 4;
  result(1, 0) = 46.2;
  result(1, 1) = 0;

  ASSERT_TRUE((matrix_a * matrix_b) == result);
}

TEST(OperatorMulNumber, test1) {
  S21Matrix matrix_a(2, 2);
  S21Matrix result(2, 2);
  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;
  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;
  ASSERT_TRUE((matrix_a * 10) == result);
}

TEST(OperatorMultiplyNum, test2) {
  S21Matrix matrix_a(2, 2);
  S21Matrix result(2, 2);
  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;
  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;
  ASSERT_TRUE((matrix_a * 10) == result);
}

TEST(OperatorSumEquel, plus1) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  a += b;
  EXPECT_DOUBLE_EQ(a(1, 1), 3.3);
}

TEST(OperatorSumEquel, plus2) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);
  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;
  matrix_a(1, 0) = -69.3;
  matrix_a(1, 1) = 0;
  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;
  result(0, 0) = -75;
  result(0, 1) = 0.56;
  result(1, 0) = -69.6;
  result(1, 1) = 2;
  ASSERT_TRUE((matrix_a += matrix_b) == result);
}

TEST(OperatorSubEquel, minus1) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);
  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;
  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;
  result(0, 0) = 10;
  result(0, 1) = 2;
  result(1, 0) = -3;
  result(1, 1) = -2;
  ASSERT_TRUE((matrix_a -= matrix_b) == result);
}

TEST(OperatorSubEquel, minus2) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  a -= b;
  EXPECT_DOUBLE_EQ(a(1, 1), -1.1);
}

TEST(OperatorMulMatrixEquel, test1) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);
  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;
  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;
  result(0, 0) = -28;
  result(0, 1) = 4;
  result(1, 0) = 46.2;
  result(1, 1) = 0;
  ASSERT_TRUE((matrix_a *= matrix_b) == result);
}

TEST(OperatorMulNumberEquel, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix result(2, 2);
  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;
  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;
  ASSERT_TRUE((matrix_a *= 10) == result);
}

TEST(OperatorEqMatrix, equal) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(1, 3);
  matrix_a = matrix_b;
  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(OperatorEqMatrix, equal1) {
  S21Matrix a(2, 3);
  S21Matrix b(2, 2);
  EXPECT_EQ(a == b, false);
  b.setCols(3);
  a(1, 1) = 1.3;
  b(1, 1) = 1.3;
  EXPECT_EQ(a == b, true);
  b(1, 2) = 1.3;
  EXPECT_EQ(a == b, false);
}

TEST(OperatorEqMatrix, equal2) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  EXPECT_EQ(a == b, true);
  a(1, 1) = 1.3;
  EXPECT_EQ(a == b, false);
  b(1, 1) = 1.3;
  EXPECT_EQ(a == b, true);
}

TEST(Operator, True) {
  S21Matrix matrix_a(2, 2);
  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;
  ASSERT_EQ(matrix_a(0, 1), 2);
}
TEST(Operator, False) {
  S21Matrix matrix_a(2, 2);
  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;
  ASSERT_NE(matrix_a(0, 1), 10);
}

TEST(Operator, brakets) {
  S21Matrix basic(2, 3);
  basic(1, 1) = 3;
  EXPECT_EQ(basic(1, 1), 3);
}

TEST(GetterAndSetter, set_zero_Matrix) {
  S21Matrix basic;
  EXPECT_EQ(basic.getRows(), 0);
  EXPECT_EQ(basic.getCols(), 0);
}

TEST(GetterAndSetter, True) {
  S21Matrix matrix_a(3, 3);
  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(0, 2) = 7;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;
  matrix_a(1, 2) = 4;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = -2;
  matrix_a(2, 2) = -3;
  ASSERT_EQ(matrix_a.getRows(), 3);
  ASSERT_EQ(matrix_a.getCols(), 3);
}

TEST(GetterAndSetter, set_rows) {
  S21Matrix basic(2, 3);
  basic(1, 1) = 2.2;
  EXPECT_EQ(basic(1, 1), 2.2);
  EXPECT_EQ(basic.getRows(), 2);
  EXPECT_EQ(basic.getCols(), 3);
  basic.setRows(4);
  basic(3, 2) = 1.2;
  EXPECT_EQ(basic(1, 1), 2.2);
  EXPECT_EQ(basic(3, 2), 1.2);
  EXPECT_EQ(basic.getRows(), 4);
  EXPECT_EQ(basic.getCols(), 3);
}

TEST(GetterAndSetter, set_cols1) {
  S21Matrix basic(3, 2);
  basic.setCols(3);
  EXPECT_EQ(basic(2, 2), 0);
}

TEST(GetterAndSetter, set_cols) {
  S21Matrix basic(2, 3);
  basic(1, 1) = 2.2;
  EXPECT_EQ(basic(1, 1), 2.2);
  EXPECT_EQ(basic.getRows(), 2);
  EXPECT_EQ(basic.getCols(), 3);
  basic.setCols(5);
  basic(1, 4) = 1.2;
  EXPECT_EQ(basic(1, 1), 2.2);
  EXPECT_EQ(basic(1, 4), 1.2);
  EXPECT_EQ(basic.getRows(), 2);
  EXPECT_EQ(basic.getCols(), 5);
}

TEST(mistake, second) {
  S21Matrix A(1, 1);
  A(0, 0) = 1;
  S21Matrix B(1, 1);
  B(0, 0) = -1;
  ASSERT_FALSE(A == B);
}

TEST(mistake, four) {
  S21Matrix A(1, 1);
  A(0, 0) = 2;
  S21Matrix B(1, 1);
  B(0, 0) = 0.5;
  ASSERT_TRUE(A.InverseMatrix() == B);
}

TEST(mistake, thirteen) {
  S21Matrix tmp(5, 5);
  tmp(0, 0) = 3;
  tmp(0, 1) = 0;
  tmp(0, 2) = 1;
  tmp(0, 3) = -1;
  tmp(0, 4) = -12;
  tmp(1, 0) = 1;
  tmp(1, 1) = 5;
  tmp(1, 2) = 1;
  tmp(1, 3) = 0;
  tmp(1, 4) = 12;
  tmp(2, 0) = 0;
  tmp(2, 1) = 1;
  tmp(2, 2) = -1;
  tmp(2, 3) = -1;
  tmp(2, 4) = 23;
  tmp(3, 0) = -1;
  tmp(3, 1) = 1;
  tmp(3, 2) = 1;
  tmp(3, 3) = 1;
  tmp(3, 4) = -134;
  tmp(4, 0) = -1;
  tmp(4, 1) = -17;
  tmp(4, 2) = 1;
  tmp(4, 3) = -1;
  tmp(4, 4) = -1;

  S21Matrix res(5, 5);
  res(0, 0) = 0.383942;
  res(0, 1) = -0.446974;
  res(0, 2) = -0.358179;
  res(0, 3) = -0.134691;
  res(0, 4) = -0.160455;
  res(1, 0) = -0.034152;
  res(1, 1) = 0.109047;
  res(1, 2) = 0.081486;
  res(1, 3) = 0.026962;
  res(1, 4) = -0.020371;
  res(2, 0) = -0.164290;
  res(2, 1) = 0.829838;
  res(2, 2) = 0.002516;
  res(2, 3) = 0.087597;
  res(2, 4) = 0.249371;
  res(3, 0) = 0.036429;
  res(3, 1) = -0.582984;
  res(3, 2) = -1.020252;
  res(3, 3) = -0.228760;
  res(3, 4) = -0.244937;
  res(4, 0) = -0.004074;
  res(4, 1) = 0.005992;
  res(4, 2) = -0.004314;
  res(4, 3) = -0.007310;
  res(4, 4) = 0.001078;
  S21Matrix t = tmp.InverseMatrix();
  ASSERT_TRUE(t == res);
}
TEST(Constructors, default_constructor) {
  S21Matrix basic;
  EXPECT_EQ(basic.getRows(), 0);
  EXPECT_EQ(basic.getCols(), 0);
}

TEST(Constructors, parameterized_constructor) {
  S21Matrix basic(2, 3);
  EXPECT_EQ(basic.getRows(), 2);
  EXPECT_EQ(basic.getCols(), 3);
}

TEST(Constructors, copy_constructor) {
  S21Matrix basic(2, 3);
  S21Matrix result(basic);
  EXPECT_EQ(result.getRows(), 2);
  EXPECT_EQ(result.getCols(), 3);
  EXPECT_EQ(basic == result, true);
}

TEST(Constructors, move_constructor) {
  S21Matrix basic(2, 3);
  S21Matrix result(std::move(basic));
  EXPECT_EQ(result.getRows(), 2);
  EXPECT_EQ(result.getCols(), 3);
  EXPECT_EQ(basic.getRows(), 0);
  EXPECT_EQ(basic.getCols(), 0);
}

TEST(Constructors, copy) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(1, 1) = 1.1;
  b(1, 1) = 2.2;
  a = b;
  EXPECT_DOUBLE_EQ(a(1, 1), 2.2);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
