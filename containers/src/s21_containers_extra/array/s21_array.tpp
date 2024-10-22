#ifndef CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERS_EXTRA_ARRAY_S21_ARRAY_TPP
#define CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERS_EXTRA_ARRAY_S21_ARRAY_TPP

namespace s21 {

template <typename T, std::size_t N>
array<T, N>::array() : size_(N) {}

template <typename T, std::size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
  std::copy(items.begin(), items.end(), data_);
}

template <typename T, std::size_t N>
array<T, N>::array(const array<T, N> &a) {
  std::copy(a.data_, a.data_ + N, data_);
}

template <typename T, std::size_t N>
array<T, N>::array(array<T, N> &&a) noexcept {
  std::move(a.data_, a.data_ + N, data_);
}

template <typename T, std::size_t N>
array<T, N> &array<T, N>::operator=(array<T, N> &&a) noexcept {
  for (size_t i = 0; i < N; ++i) {
    data_[i] = std::move(a.data_[i]);
  }
  return *this;
}

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Error: Index out of range");
  }
  return data_[pos];
}

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Error: Index out of range");
  }
  return data_[pos];
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::front() {
  return data_[0];
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::back() {
  return data_[size_ - 1];
}

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::data() noexcept {
  return data_;
}

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
  return data_;
}

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::end() {
  return data_ + size_;
}

template <typename T, std::size_t N>
bool array<T, N>::empty() const {
  return size_ == 0;
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::size() const {
  return size_;
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::max_size() const {
  return size();
}
template <typename T, std::size_t N>
void array<T, N>::swap(array<T, N> &other) {
  std::swap_ranges(data_, data_ + size_, other.data_);
}

template <typename T, std::size_t N>
void array<T, N>::fill(const_reference value) {
  std::fill(data_, data_ + size_, value);
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_S21_CONTAINERS_EXTRA_ARRAY_S21_ARRAY_TPP
