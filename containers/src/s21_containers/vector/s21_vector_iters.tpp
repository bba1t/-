#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERS_VECTOR_S21_VECTORS_ITERS_TPP_
#define CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERS_VECTOR_S21_VECTORS_ITERS_TPP_

namespace s21 {

template <typename T>
vector<T>::VectorIterator::VectorIterator(T* ptr) : ptr_(ptr){};

template <typename T>
typename vector<T>::reference vector<T>::VectorIterator::operator*() {
  return *ptr_;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator++(int) {
  VectorIterator copy(*this);
  ++ptr_;
  return copy;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator--(int) {
  VectorIterator copy(*this);
  --ptr_;
  return copy;
}

template <typename T>
typename vector<T>::VectorIterator& vector<T>::VectorIterator::operator++() {
  ++ptr_;
  return *this;
}

template <typename T>
typename vector<T>::VectorIterator& vector<T>::VectorIterator::operator--() {
  --ptr_;
  return *this;
}

template <typename T>
bool vector<T>::VectorIterator::operator==(const VectorIterator& other) const {
  return ptr_ == other.ptr_;
}

template <typename T>
bool vector<T>::VectorIterator::operator!=(const VectorIterator& other) const {
  return ptr_ != other.ptr_;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator+(
    int n) const {
  VectorIterator copy(*this);
  for (int i = 0; i < n; ++i) {
    ++copy;
  }
  return copy;
}

template <typename T>
typename vector<T>::VectorIterator vector<T>::VectorIterator::operator-(
    int n) const {
  VectorIterator copy(*this);
  for (int i = 0; i < n; ++i) {
    copy--;
  }
  return copy;
}

template <typename T>
ptrdiff_t vector<T>::VectorIterator::operator-(
    const VectorIterator& other) const {
  return ptr_ - other.ptr_;
}

template <typename T>
vector<T>::VectorConstIterator::VectorConstIterator(const T* ptr) : ptr_(ptr) {}

template <typename T>
typename vector<T>::const_reference vector<T>::VectorConstIterator::operator*()
    const {
  return *ptr_;
}

template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator++(int) {
  VectorConstIterator copy(*this);
  ++ptr_;
  return copy;
}

template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator--(int) {
  VectorConstIterator copy(*this);
  --ptr_;
  return copy;
}

template <typename T>
typename vector<T>::VectorConstIterator&
vector<T>::VectorConstIterator::operator++() {
  ++ptr_;
  return *this;
}

template <typename T>
typename vector<T>::VectorConstIterator&
vector<T>::VectorConstIterator::operator--() {
  --ptr_;
  return *this;
}

template <typename T>
bool vector<T>::VectorConstIterator::operator==(
    const VectorConstIterator& other) const {
  return ptr_ == other.ptr_;
}

template <typename T>
bool vector<T>::VectorConstIterator::operator!=(
    const VectorConstIterator& other) const {
  return ptr_ != other.ptr_;
}

template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator+(int n) const {
  VectorConstIterator copy(*this);
  for (int i = 0; i < n; i++) {
    copy++;
  }
  return copy;
}

template <typename T>
typename vector<T>::VectorConstIterator
vector<T>::VectorConstIterator::operator-(int n) const {
  VectorConstIterator copy(*this);
  for (int i = 0; i < n; i++) {
    copy--;
  }
  return copy;
}

template <typename T>
ptrdiff_t vector<T>::VectorConstIterator::operator-(
    const VectorConstIterator& other) const {
  return ptr_ - other.ptr_;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERS_VECTOR_S21_VECTORS_ITERS_TPP_
