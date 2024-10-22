#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERS_VECTOR_S21_VECTORS_ITERS_H
#define CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERS_VECTOR_S21_VECTORS_ITERS_H

namespace s21 {

template <typename T>
class vector<T>::VectorIterator {
 public:
  VectorIterator() = default;
  VectorIterator(T* ptr);

  reference operator*();
  VectorIterator operator++(int);
  VectorIterator operator--(int);
  VectorIterator& operator++();
  VectorIterator& operator--();
  bool operator==(const VectorIterator& other) const;
  bool operator!=(const VectorIterator& other) const;
  VectorIterator operator+(int n) const;
  VectorIterator operator-(int n) const;
  ptrdiff_t operator-(const VectorIterator& other) const;

 private:
  T* ptr_;
};

template <typename T>
class vector<T>::VectorConstIterator {
 public:
  VectorConstIterator() = default;
  VectorConstIterator(const T* ptr);

  const_reference operator*() const;
  VectorConstIterator operator++(int);
  VectorConstIterator operator--(int);
  VectorConstIterator& operator++();
  VectorConstIterator& operator--();
  bool operator==(const VectorConstIterator& other) const;
  bool operator!=(const VectorConstIterator& other) const;
  VectorConstIterator operator+(int n) const;
  VectorConstIterator operator-(int n) const;
  ptrdiff_t operator-(const VectorConstIterator& other) const;

 private:
  const T* ptr_;
};

}  // namespace s21

#include "s21_vector_iters.tpp"

#endif  // CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERS_VECTOR_S21_VECTORS_ITERS_H