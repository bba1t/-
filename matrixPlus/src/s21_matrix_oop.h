#ifndef S21_MATRIX_PLUS_SRC_S21_MATRIX_OOP_H
#define S21_MATRIX_PLUS_SRC_S21_MATRIX_OOP_H

#include <cmath>
#include <iostream>
#include <stdexcept>

class S21Matrix {
 public:
  S21Matrix();  // Default constructor
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();  // Destructor
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix& other);
  S21Matrix operator=(const S21Matrix& other);
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix operator*=(const double num);
  double& operator()(int i, int j);

  int getRows();
  int getCols();
  void setRows(int rows);
  void setCols(int cols);
  void nullMatrix(const S21Matrix& other);
  double getMatrix(int rows, int cols);
  void setMatrix(int rows, int cols, double value);
  void SumMatrix(const S21Matrix& other);
  bool EqMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated
  void creatMatrix();
  S21Matrix create_complements_matrix(const S21Matrix& other);
  double getDeterminant(const S21Matrix& other, int rows);
  S21Matrix creatMinor(const S21Matrix& other, int size, int rows, int cols);
};

#endif  // S21_MATRIX_PLUS_SRC_S21_MATRIX_OOP_H