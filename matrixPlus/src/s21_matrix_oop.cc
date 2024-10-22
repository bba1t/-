#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw std::out_of_range("Incorrect size");
  } else {
    rows_ = rows;
    cols_ = cols;
    matrix_ = new double *[rows_];
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_];
    }
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = 0;
      }
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::creatMatrix() {
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

int S21Matrix::getCols() { return cols_; }

int S21Matrix::getRows() { return rows_; }

void S21Matrix::setRows(int rows) {
  if (rows < 1) {
    throw std::out_of_range("Incorrect size");
  }
  S21Matrix result(rows, cols_);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i < rows_) {
        result.matrix_[i][j] = matrix_[i][j];
      } else {
        result.matrix_[i][j] = 0;
      }
    }
  }
  nullMatrix(result);
}

void S21Matrix::setCols(int cols) {
  if (cols < 1) {
    throw std::out_of_range("Incorrect size");
  }
  S21Matrix result(rows_, cols);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols; j++) {
      if (j < cols_) {
        result.matrix_[i][j] = matrix_[i][j];
      } else {
        result.matrix_[i][j] = 0;
      }
    }
  }
  nullMatrix(result);
}

void S21Matrix::nullMatrix(const S21Matrix &other) {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;

  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

double S21Matrix::getMatrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw std::out_of_range("Incorrect size");
  }
  return matrix_[rows][cols];
}

void S21Matrix::setMatrix(int rows, int cols, double value) {
  if (rows < 0 || rows >= rows_ || cols < 0 || cols >= cols_) {
    throw std::out_of_range("Incorrect size");
  } else {
    matrix_[rows][cols] = value;
  }
}

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool status = true;
  int flag = 0;
  if (rows_ < 1 || cols_ < 1) {
    throw std::out_of_range("Incorrect size");
  }
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    status = false;
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-6) {
          status = false;
          flag = 1;
          break;
        }
      }
      if (flag) {
        break;
      }
    }
  }
  return status;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (this->rows_ < 1 || this->rows_ < 1 || other.rows_ < 1 ||
      other.cols_ < 1) {
    throw std::out_of_range("Incorrect size");
  } else if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw std::logic_error("Incorrect index");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ < 1 || cols_ < 1) {
    throw std::out_of_range("Incorrect size");
  } else if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw std::logic_error("Incorrect index");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (this->rows_ < 1 || this->rows_ < 1 || other.rows_ < 1 ||
      other.cols_ < 1) {
    throw std::out_of_range("Incorrect size");
  } else if (this->cols_ != other.rows_) {
    throw std::logic_error("Incorrect index");
  } else {
    S21Matrix result(rows_, other.cols_);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        result.matrix_[i][j] = 0;
        for (int k = 0; k < other.rows_; k++) {
          result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    rows_ = result.rows_;
    cols_ = result.cols_;
    creatMatrix();
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = result.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  if (rows_ < 1 || cols_ < 1) {
    throw std::out_of_range("Incorrect size");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = matrix_[i][j] * num;
      }
    }
  }
}

S21Matrix S21Matrix::Transpose() {
  if (rows_ < 1 || cols_ < 1) {
    throw std::out_of_range("Incorrect size");
  }
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ < 1 || cols_ < 1) {
    throw std::out_of_range("Incorrect size");
  }
  if (rows_ != cols_) {
    throw std::logic_error("Incorrect index");
  }
  S21Matrix result = create_complements_matrix(*this);
  return result;
}

S21Matrix S21Matrix::create_complements_matrix(const S21Matrix &other) {
  int size = other.rows_;
  int degree = 1;
  S21Matrix res_1(size, size);
  if (size == 1) {
    res_1.matrix_[0][0] = 1;
  } else {
    for (int i = 0; i < size; i++) {
      degree = i % 2 ? -1 : 1;
      for (int j = 0; j < size; j++) {
        S21Matrix res = creatMinor(other, size, i, j);
        double temp = getDeterminant(res, size - 1);
        res_1.matrix_[i][j] = degree * temp;
        degree *= (-1);
      }
    }
  }
  return res_1;
}

double S21Matrix::Determinant() {
  double result = 0;
  if (rows_ < 1 || cols_ < 1) {
    throw std::out_of_range("Incorrect size");
  }
  if (rows_ != cols_) {
    throw std::logic_error("Incorrect index");
  } else {
    result = getDeterminant(*this, rows_);
  }
  return result;
}

double S21Matrix::getDeterminant(const S21Matrix &other, int size) {
  double det = 0;
  int degree = 1;
  if (size == 1) {
    det = other.matrix_[0][0];
  } else if (size == 2) {
    det = other.matrix_[0][0] * other.matrix_[1][1] -
          (other.matrix_[0][1] * other.matrix_[1][0]);
  } else {
    for (int j = 0; j < size; j++) {
      S21Matrix res = creatMinor(other, size, 0, j);
      det += degree * (other.matrix_[0][j] * getDeterminant(res, size - 1));
      degree *= (-1);
    }
  }
  return det;
}

S21Matrix S21Matrix::creatMinor(const S21Matrix &other, int size, int rows,
                                int cols) {
  int set_row = 0;
  int set_col = 0;
  S21Matrix A(other.rows_ - 1, other.cols_ - 1);
  for (int i = 0; i < size - 1; i++) {
    if (i == rows) {
      set_row = 1;
    }
    set_col = 0;
    for (int j = 0; j < size - 1; j++) {
      if (j == cols) {
        set_col = 1;
      }
      A.matrix_[i][j] = other.matrix_[i + set_row][j + set_col];
    }
  }
  return A;
}
S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ < 1 || cols_ < 1) {
    throw std::out_of_range("Incorrect size");
  }
  S21Matrix result(rows_, cols_);
  if (rows_ == 1 && cols_ == 1) {
    result.matrix_[0][0] = 1.0 / matrix_[0][0];
  } else {
    double determinant = Determinant();
    if (fabs(determinant) < 1e-7) {
      throw std::logic_error("Determinast == 0");
    }
    S21Matrix calc = CalcComplements();
    S21Matrix trancpote = calc.Transpose();
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < rows_; j++) {
        result.matrix_[i][j] = trancpote.matrix_[i][j] / determinant;
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix res(*this);
  res.SumMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix res(*this);
  res.SubMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix res(*this);
  res.MulMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix res(*this);
  res.MulNumber(num);
  return res;
}

bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

S21Matrix S21Matrix::operator=(const S21Matrix &other) {
  if (this == &other) {
    return *this;
  }
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  creatMatrix();
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

S21Matrix S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

double &S21Matrix::operator()(int i, int j) {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    throw std::out_of_range("Incorrect index");
  }
  return matrix_[i][j];
}