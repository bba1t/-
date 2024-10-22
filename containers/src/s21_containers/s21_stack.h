#ifndef CPP2_S21_CONTAINERS_2_SRC_STACK_S21_STACK_H
#define CPP2_S21_CONTAINERS_2_SRC_STACK_S21_STACK_H

#include <iostream>

namespace s21 {
template <typename T>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  stack() noexcept;
  stack(std::initializer_list<value_type> const &items) noexcept;
  ~stack();

  void pop();
  const_reference top() const;
  void push(const_reference value) noexcept;
  void swap(stack &other) noexcept;

  stack(stack &&other) noexcept;
  stack &operator=(stack &&other) noexcept;
  stack(const stack &s);
  stack &operator=(const stack &s) noexcept;

  size_type size() const noexcept { return size_; };
  bool empty() const noexcept;

 private:
  template <typename>
  class Node_ {
   public:
    value_type data_;
    Node_ *p_prev_;

    Node_(T data_ = T(), Node_ *p_prev_ = nullptr) {
      this->data_ = data_;
      this->p_prev_ = p_prev_;
    }
  };
  Node_<T> *top_;
  size_type size_;

  void Clear_();
  value_type At_(int i) const;
};

template <typename T>
inline stack<T>::stack() noexcept : top_(nullptr), size_(0) {}

template <typename T>
inline stack<T>::stack(std::initializer_list<value_type> const &items) noexcept
    : top_(nullptr), size_(0) {
  for (size_type i : items) {
    push(i);
  }
}

template <typename T>
inline stack<T>::~stack() {
  Clear_();
}

template <typename T>
typename stack<T>::const_reference stack<T>::top() const {
  if (empty()) throw std::logic_error("Stack is empty");
  return top_->data_;
}

template <typename T>
inline void stack<T>::push(const_reference value) noexcept {
  Node_<T> *newNode_ = new Node_<T>(value);
  if (!top_) {
    top_ = newNode_;
  } else {
    newNode_->p_prev_ = top_;
    top_ = newNode_;
  }
  size_++;
}

template <typename T>
inline void stack<T>::pop() {
  Node_<T> *tmp = top_;
  top_ = top_->p_prev_;
  delete tmp;
  size_--;
}

template <typename T>
inline void stack<T>::swap(stack<T> &other) noexcept {
  if (this != &other) {
    Node_<T> *current_ = this->top_;
    this->top_ = other.top_;
    other.top_ = current_;

    size_type tmp_size = this->size_;
    this->size_ = other.size_;
    other.size_ = tmp_size;
  }
}

template <typename T>
inline stack<T>::stack(stack<T> &&other) noexcept : top_(nullptr), size_(0) {
  *this = std::move(other);
}

template <typename T>
inline stack<T> &stack<T>::operator=(stack<T> &&other) noexcept {
  if (this != &other) {
    Clear_();
    this->top_ = other.top_;
    this->size_ = other.size_;
    other.top_ = nullptr;
    other.size_ = 0;
  }
  return *this;
}

template <typename T>
inline stack<T>::stack(const stack<T> &other) : top_(nullptr), size_(0) {
  *this = other;
}

template <typename T>
inline stack<T> &stack<T>::operator=(const stack<T> &other) noexcept {
  if (this != &other) {
    Clear_();
    int index = other.size_ - 1;
    while (index >= 0) push(other.At_(index--));
  }
  return *this;
}

template <typename T>
inline typename stack<T>::value_type stack<T>::At_(int index) const {
  if (index < 0 || index >= (int)size_)
    throw std::out_of_range("Index out of range");

  value_type result = T();
  Node_<T> *current_ = top_;
  int j = 0;

  while ((j++) != index) current_ = current_->p_prev_;

  result = current_->data_;
  return result;
}

template <typename T>
inline bool stack<T>::empty() const noexcept {
  if (size_ == 0)
    return true;
  else
    return false;
}

template <typename T>
inline void stack<T>::Clear_() {
  while (size_ != 0) {
    pop();
  }
}

}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_SRC_STACK_S21_STACK_H
