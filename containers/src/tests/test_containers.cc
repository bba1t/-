#include <gtest/gtest.h>

#include <array>
#include <stack>
#include <vector>

#include "../s21_containersplus.h"

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА STACK (START) ==========
*/

TEST(StackTest, Constructor_default) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Constructor_initializer_list_1) {
  s21::stack<int> s21_stack{1, 2, 4};
  EXPECT_EQ(s21_stack.size(), static_cast<unsigned long>(3));
  EXPECT_EQ(s21_stack.top(), 4);
}

TEST(StackTest, Constructor_initializer_list_2) {
  std::initializer_list<int> b;
  s21::stack<int> s21_stack{b};
  std::stack<int> std_stack{b};
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Constructor_copy_1) {
  std::initializer_list<int> il1 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_copy{s21_stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_copy{std_stack};
  EXPECT_EQ(s21_stack_copy.size(), std_stack_copy.size());
  EXPECT_EQ(s21_stack_copy.top(), std_stack_copy.top());
}

TEST(StackTest, Constructor_move_1) {
  std::initializer_list<int> il1 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{s21_stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{std_stack};
  EXPECT_EQ(s21_stack_move.size(), std_stack_move.size());
  EXPECT_EQ(s21_stack_move.top(), std_stack_move.top());
}

TEST(StackTest, Opertator_move_1) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Opertator_move_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Opertator_move_3) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_move{il2};
  s21_stack = std::move(s21_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Top_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};

  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Top_2_throw) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};

  EXPECT_THROW(s21_stack.top(), std::logic_error);
}

TEST(StackTest, Empty_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackTest, Empty_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(StackTest, Size_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Size_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(StackTest, Push_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Push_2) {
  std::initializer_list<int> il1;

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(StackTest, Pop_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  std::stack<int> std_stack{il1};
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

//  TEST(StackTest, Pop_2) {
//    std::initializer_list<int> il1;

//    s21::stack<int> s21_stack{il1};
//    std::stack<int> std_stack{il1};
//    s21_stack.pop();
//    std_stack.pop();
//    EXPECT_EQ(s21_stack.size(), static_cast<unsigned long>(0));
//  }

TEST(StackTest, Swap_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, Swap_2) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, Swap_3) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2;

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_4) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_5) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2;

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_6) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> s21_stack{il1};
  s21::stack<int> s21_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  s21_stack.swap(s21_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  EXPECT_EQ(s21_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(s21_stack_swap.top(), std_stack_swap.top());
}

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА STACK (END) ==========
*/

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА VECTOR (START) ==========
*/

TEST(VectorTest, DefaultConstructor_EmptyVector) {
  s21::vector<int> v;
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
}

TEST(VectorTest, SizeConstructor_PositiveSize) {
  const size_t size = 5;
  s21::vector<int> v(size);
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), size);
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(v[i], 0);
  }
}

TEST(VectorTest, SizeConstructor_ZeroSize) {
  const size_t size = 0;
  s21::vector<int> v(size);
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), size);
}

TEST(VectorTest, InitializerListConstructor_EmptyList) {
  s21::vector<int> v = {};
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
}

TEST(VectorTest, InitializerListConstructor_NonEmptyList) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), 5);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[4], 5);
}

TEST(VectorTest, CopyConstructor_EmptyVector) {
  s21::vector<int> v1;
  s21::vector<int> v2(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(VectorTest, CopyConstructor_NonEmptyVector) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2(v1);
  EXPECT_EQ(v2.size(), v1.size());
  for (size_t i = 0; i < v1.size(); ++i) {
    EXPECT_EQ(v2[i], v1[i]);
  }
}

TEST(VectorTest, MoveConstructor_EmptyVector) {
  s21::vector<int> v1;
  s21::vector<int> v2(std::move(v1));
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(VectorTest, MoveConstructor_NonEmptyVector) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2(std::move(v1));
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());  // Source vector should be empty after move
}

TEST(VectorTest, Destructor_EmptyVector) {
  s21::vector<int>* v = new s21::vector<int>();
  delete v;  // Destructor should be called here
  // No specific assertions, but this ensures the destructor is working
}

TEST(VectorTest, Destructor_NonEmptyVector) {
  s21::vector<int>* v = new s21::vector<int>{1, 2, 3};
  delete v;  // Destructor should be called here
  // No specific assertions, but this ensures the destructor is working
}

TEST(VectorTest, MoveAssignmentOperator_EmptyToEmpty) {
  s21::vector<int> v1;
  s21::vector<int> v2;
  v2 = std::move(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(VectorTest, MoveAssignmentOperator_NonEmptyToEmpty) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2;
  v2 = std::move(v1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());  // Source vector should be empty after move
}

TEST(VectorTest, MoveAssignmentOperator_EmptyToNonEmpty) {
  s21::vector<int> v1;
  s21::vector<int> v2 = {4, 5, 6};
  v2 = std::move(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(VectorTest, MoveAssignmentOperator_NonEmptyToNonEmpty) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2 = {4, 5, 6};
  v2 = std::move(v1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());  // Source vector should be empty after move
}

TEST(VectorTest, At_ValidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.at(0), 1);
  EXPECT_EQ(v.at(2), 3);
  EXPECT_EQ(v.at(4), 5);
}

TEST(VectorTest, At_InvalidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_THROW(v.at(5), std::out_of_range);
  EXPECT_THROW(v.at(10), std::out_of_range);
}

TEST(VectorTest, IndexOperator_ValidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[4], 5);
}

TEST(VectorTest, IndexOperator_InvalidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_ANY_THROW(v[5]);
  EXPECT_ANY_THROW(v[10]);
}

TEST(VectorTest, ConstIndexOperator_ValidIndex) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[4], 5);
}

TEST(VectorTest, ConstIndexOperator_InvalidIndex) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_ANY_THROW(v[5]);
  EXPECT_ANY_THROW(v[10]);
}

TEST(VectorTest, FrontConst_ValidVector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.front(), 1);
}

TEST(VectorTest, FrontConst_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_THROW(v.front(), std::out_of_range);
}

TEST(VectorTest, BackConst_ValidVector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.back(), 5);
}

TEST(VectorTest, BackConst_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_THROW(v.back(), std::out_of_range);
}

TEST(VectorTest, Data_ValidVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  int* dataPtr = v.data();
  EXPECT_EQ(*dataPtr, 1);
  // Modify the data through the pointer and check if the vector is updated
  *dataPtr = 10;
  EXPECT_EQ(v[0], 10);
}

TEST(VectorTest, Data_EmptyVector) {
  s21::vector<int> v;
  int* dataPtr = v.data();
  // Data pointer of an empty vector can be anything
  EXPECT_EQ(dataPtr, nullptr);
}

TEST(VectorTest, Begin_ValidVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.begin();
  EXPECT_EQ(*it, 1);
  // Modify the data through the iterator and check if the vector is updated
  *it = 10;
  EXPECT_EQ(v[0], 10);
}

TEST(VectorTest, Begin_EmptyVector) {
  s21::vector<int> v;
  auto it = v.begin();
  // The begin() of an empty vector should be the end() too, so iterator should
  // be equal to end()
  EXPECT_EQ(it, v.end());
}

TEST(VectorTest, End_ValidVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.end();
  // end() iterator should not be dereferenced; comparing it to another iterator
  // should work
  auto beginIt = v.begin();
  EXPECT_NE(it, beginIt);
}

TEST(VectorTest, End_EmptyVector) {
  s21::vector<int> v;
  auto it = v.end();
  // The end() of an empty vector should be the begin() too, so iterator should
  // be equal to begin()
  EXPECT_EQ(it, v.begin());
}

TEST(VectorTest, CBegin_ValidVector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.cbegin();
  EXPECT_EQ(*it, 1);
  // Modify the data through the iterator and check if the vector is not updated
  // (should be const_iterator) Uncommenting the following line should result in
  // a compilation error. *it = 10;
}

TEST(VectorTest, CBegin_EmptyVector) {
  const s21::vector<int> v;
  auto it = v.cbegin();
  // The cbegin() of an empty vector should be the cend() too, so iterator
  // should be equal to cend()
  EXPECT_EQ(it, v.cend());
}

TEST(VectorTest, CEnd_ValidVector) {
  const s21::vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.cend();
  // cend() iterator should not be dereferenced; comparing it to another
  // iterator should work
  auto beginIt = v.cbegin();
  EXPECT_EQ(it, beginIt + 5);
}

TEST(VectorTest, CEnd_EmptyVector) {
  const s21::vector<int> v;
  auto it = v.cend();
  // The cend() of an empty vector should be the cbegin() too, so iterator
  // should be equal to cbegin()
  EXPECT_EQ(it, v.cbegin());
}

TEST(VectorTest, Empty_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_TRUE(v.empty());
}

TEST(VectorTest, Empty_NonEmptyVector) {
  const s21::vector<int> v = {1, 2, 3};
  EXPECT_FALSE(v.empty());
}

TEST(VectorTest, Size_EmptyVector) {
  const s21::vector<int> v;
  EXPECT_EQ(v.size(), 0);
}

TEST(VectorTest, Size_NonEmptyVector) {
  const s21::vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.size(), 3);
}

TEST(VectorTest, MaxSize) {
  const s21::vector<int> v;
  // You can't predict the exact max size, but it should be a very large value
  EXPECT_GT(v.max_size(), 0);
}

TEST(VectorTest, Reserve_IncreaseCapacity) {
  s21::vector<int> v;
  size_t initialCapacity = v.capacity();
  size_t newCapacity = initialCapacity + 10;
  v.reserve(newCapacity);
  EXPECT_GE(v.capacity(), newCapacity);
}

TEST(VectorTest, Reserve_DecreaseCapacity) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  size_t newCapacity = initialCapacity - 2;
  v.reserve(newCapacity);
  // Capacity may not decrease immediately, but it shouldn't exceed the
  // requested value
  EXPECT_LE(v.capacity(), initialCapacity);
  EXPECT_GE(v.capacity(), newCapacity);
}

TEST(VectorTest, Capacity_EmptyVector) {
  const s21::vector<int> v;
  // The capacity of an empty vector should be at least 0
  EXPECT_GE(v.capacity(), 0);
}

TEST(VectorTest, Capacity_NonEmptyVector) {
  const s21::vector<int> v = {1, 2, 3};
  // The capacity of a non-empty vector might vary, but it should be at least
  // the size of the vector
  EXPECT_GE(v.capacity(), v.size());
}

TEST(VectorTest, ShrinkToFit_EmptyVector) {
  s21::vector<int> v;
  v.shrink_to_fit();
  // After shrink_to_fit() on an empty vector, the capacity should still be at
  // least 0
  EXPECT_GE(v.capacity(), 0);
}

TEST(VectorTest, ShrinkToFit_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  v.pop_back();  // Simulate a reduction in size
  v.shrink_to_fit();
  // After shrink_to_fit(), the capacity should not exceed the new size
  EXPECT_LE(v.capacity(), v.size());
  // The capacity may not necessarily decrease, but it should not be larger than
  // the initial capacity
  EXPECT_LE(v.capacity(), initialCapacity);
}

TEST(VectorTest, Clear_EmptyVector) {
  s21::vector<int> v;
  v.clear();
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
  // Clearing an empty vector should not affect capacity
  EXPECT_GE(v.capacity(), 0);
}

TEST(VectorTest, Clear_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  v.clear();
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
  // Clearing a vector should not affect capacity immediately
  EXPECT_GE(v.capacity(), 0);
}

TEST(VectorTest, Insert_Beginning) {
  s21::vector<int> v = {2, 3, 4};
  auto it = v.insert(v.begin(), 1);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(*it, 1);
}

TEST(VectorTest, Insert_Middle) {
  s21::vector<int> v = {1, 3, 4};
  auto it = v.insert(v.begin() + 1, 2);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(*it, 2);
}

TEST(VectorTest, Insert_End) {
  s21::vector<int> v = {1, 2, 3};
  auto it = v.insert(v.end(), 4);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[3], 4);
  EXPECT_EQ(*it, 4);
}

TEST(VectorTest, Erase_Beginning) {
  s21::vector<int> v = {1, 2, 3, 4};
  v.erase(v.begin());  // Erase the first element
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[0], 2);
}

TEST(VectorTest, Erase_Middle) {
  s21::vector<int> v = {1, 2, 3, 4};
  v.erase(v.begin() + 1);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[1], 3);
}

TEST(VectorTest, Erase_End) {
  s21::vector<int> v = {1, 2, 3, 4};
  v.erase(v.end() - 1);  // Erase the last element
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[2], 3);
}

TEST(VectorTest, PushBack_EmptyVector) {
  s21::vector<int> v;
  v.push_back(1);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v[0], 1);
}

TEST(VectorTest, PushBack_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3};
  v.push_back(4);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[3], 4);
}

TEST(VectorTest, PopBack_NonEmptyVector) {
  s21::vector<int> v = {1, 2, 3};
  v.pop_back();
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.back(), 2);
}

TEST(VectorTest, PopBack_EmptyVector) {
  s21::vector<int> v;
  // Popping from an empty vector should not cause an error (undefined behavior
  // for some std::vector implementations)
  v.pop_back();
  EXPECT_TRUE(v.empty());
}

TEST(VectorTest, Swap_NonEmptyVectors) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2 = {4, 5, 6};

  v1.swap(v2);

  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v2.size(), 3);

  EXPECT_EQ(v1[0], 4);
  EXPECT_EQ(v1[2], 6);

  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[2], 3);
}

TEST(VectorTest, Swap_EmptyAndNonEmptyVectors) {
  s21::vector<int> v1;
  s21::vector<int> v2 = {1, 2, 3};

  v1.swap(v2);

  EXPECT_EQ(v1.size(), 3);
  EXPECT_FALSE(v1.empty());
  EXPECT_EQ(v2.size(), 0);
  EXPECT_TRUE(v2.empty());
}

TEST(VectorTest, InsertMany) {
  s21::vector<int> vec = {1, 2, 3, 7, 8};
  s21::vector<int>::const_iterator pos = vec.cbegin() + 3;

  vec.insert_many(pos, 4, 5, 6);

  // Check the size of the vector after insertion
  EXPECT_EQ(vec.size(), 8);

  // Check the elements after insertion
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 4);
  EXPECT_EQ(vec[4], 5);
  EXPECT_EQ(vec[5], 6);
  EXPECT_EQ(vec[6], 7);
  EXPECT_EQ(vec[7], 8);
}

TEST(VectorTest, InsertManyBack) {
  s21::vector<int> vec = {1, 2, 3};

  vec.insert_many_back(4, 5, 6);

  // Check the size of the vector after insertion
  EXPECT_EQ(vec.size(), 6);

  // Check the elements after insertion
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 4);
  EXPECT_EQ(vec[4], 5);
  EXPECT_EQ(vec[5], 6);
}

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА VECTOR (END) ==========
*/

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА ARRAY (START) ==========
*/

TEST(ArrayTest, DefaultConstructor) {
  s21::array<int, 5> arr;
  // Check that the size is correct
  EXPECT_EQ(arr.size(), 5);

  // Check that all elements are initialized to their default value (0 for int)
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], 0);
  }
}

TEST(ArrayTest, InitListConstructor) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};

  // Check that the size is correct
  EXPECT_EQ(arr.size(), 5);

  // Check that each element is initialized correctly
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], static_cast<int>(i) + 1);
  }
}

TEST(ArrayTest, CopyConstructor) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  s21::array<int, 5> arrCopy(arr);

  // Check that the size is correct
  EXPECT_EQ(arrCopy.size(), 5);

  // Check that the elements are copied correctly
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arrCopy[i], arr[i]);
  }
}

TEST(ArrayTest, MoveConstructor) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  s21::array<int, 5> arrMoved(std::move(arr));

  // Check that the size is correct
  EXPECT_EQ(arrMoved.size(), 5);

  // Check that the elements are moved correctly
  for (size_t i = 0; i < arrMoved.size(); ++i) {
    EXPECT_EQ(arrMoved[i], static_cast<int>(i) + 1);
  }
}

TEST(ArrayTest, Begin) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto it = arr.begin();
  EXPECT_EQ(*it, 1);
  // Modify the data through the iterator and check if the array is updated
  *it = 10;
  EXPECT_EQ(arr[0], 10);
}

TEST(ArrayTest, End) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  auto it = arr.end();
  // end() iterator should not be dereferenced; comparing it to another iterator
  // should work
  auto beginIt = arr.begin();
  EXPECT_EQ(it, beginIt + 5);
}

TEST(ArrayTest, At_ValidIndex) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.at(2);
  EXPECT_EQ(value, 3);
}

TEST(ArrayTest, At_OutOfBounds) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  // Attempting to access an out-of-bounds index using at() should throw an
  // exception
  EXPECT_THROW(arr.at(10), std::out_of_range);
}

TEST(ArrayTest, Front) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.front();
  EXPECT_EQ(value, 1);
}

TEST(ArrayTest, Back) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  int value = arr.back();
  EXPECT_EQ(value, 5);
}

TEST(ArrayTest, Empty_NonEmptyArray) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_FALSE(arr.empty());
}

TEST(ArrayTest, Empty_EmptyArray) {
  s21::array<int, 0> arr;
  EXPECT_TRUE(arr.empty());
}

TEST(ArrayTest, Size_NonEmptyArray) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_EQ(arr.size(), 5);
}

TEST(ArrayTest, Size_EmptyArray) {
  s21::array<int, 0> arr;
  EXPECT_EQ(arr.size(), 0);
}

TEST(ArrayTest, MaxSize) {
  s21::array<int, 5> arr;
  // The max size of an array with a specified size is the same as its declared
  // size
  EXPECT_EQ(arr.max_size(), 5);
}

TEST(ArrayTest, Swap) {
  s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};

  arr1.swap(arr2);

  // Check that the elements of arr1 are now from arr2
  for (size_t i = 0; i < arr1.size(); ++i) {
    EXPECT_EQ(arr1[i], static_cast<int>(i) + 6);
  }

  // Check that the elements of arr2 are now from arr1
  for (size_t i = 0; i < arr2.size(); ++i) {
    EXPECT_EQ(arr2[i], static_cast<int>(i) + 1);
  }
}

TEST(ArrayTest, Fill) {
  s21::array<int, 5> arr;
  arr.fill(10);

  // Check that all elements are filled with the specified value
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], 10);
  }
}

TEST(ArrayTest, MoveAssignmentOperator) {
  s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};

  arr1 = std::move(arr2);

  // Check that arr1 now contains the same elements as arr2
  for (size_t i = 0; i < arr1.size(); ++i) {
    EXPECT_EQ(arr1[i], static_cast<int>(i) + 6);
  }
}

TEST(ArrayTest, OperatorBracket) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};

  // Check that elements can be accessed using the [] operator
  for (size_t i = 0; i < arr.size(); ++i) {
    EXPECT_EQ(arr[i], static_cast<int>(i) + 1);
  }

  // Modify an element using the [] operator and check if the array is updated
  arr[2] = 10;
  EXPECT_EQ(arr[2], 10);
}

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА ARRAY (END) ==========
*/



/*
    ========== ТЕСТЫ КОНТЕЙНЕРА SET (START) ==========
*/

TEST(set_test, constructor1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  std::set<int>::iterator it2 = s2.begin();
  EXPECT_EQ(s1.size(), s2.size());
  for (; it2 != s2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
}

TEST(set_test, constructor2) {
  s21::set<int> s1;
  std::set<int> s2;
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, constructor3) {
  const s21::set<int> s1{4};
  const std::set<int> s2{4};
  s21::set<int>::const_iterator it1 = s1.begin();
  std::set<int>::const_iterator it2 = s2.begin();
  EXPECT_EQ(s1.size(), s2.size());
  for (; it2 != s2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
}

TEST(set_test, constructor4) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11 = s1;
  std::set<int> s22 = s2;
  s21::set<int>::iterator it1 = s11.begin();
  for (std::set<int>::iterator it2 = s22.begin(); it2 != s22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
}

TEST(set_test, constructor5) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11 = std::move(s1);
  std::set<int> s22 = std::move(s2);
  s21::set<int>::iterator it1 = s11.begin();
  for (std::set<int>::iterator it2 = s22.begin(); it2 != s22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
}

TEST(set_test, move_operator1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11;
  std::set<int> s22;
  s11 = std::move(s1);
  s22 = std::move(s2);
  s21::set<int>::iterator it1 = s11.begin();
  for (std::set<int>::iterator it2 = s22.begin(); it2 != s22.end();
       ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
}

TEST(set_test, begin1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  std::set<int>::iterator it2 = s2.begin();
  EXPECT_EQ(*it1, *it2);
}

TEST(set_test, end1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.end();
  std::set<int>::iterator it2 = s2.end();
  --it1, --it2;
  EXPECT_EQ(*it2, *it1);
}

TEST(set_test, end2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.end();
  EXPECT_THROW(*it1, std::invalid_argument);
}

TEST(set_test, iterator1) {
  s21::set<int>::iterator it;
  EXPECT_THROW(*it, std::invalid_argument);
}

TEST(set_test, iterator2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.end();
  std::set<int>::iterator it2 = s2.end();
  --it1, --it2;
  for (; it2 != s2.begin(); --it1, --it2) EXPECT_EQ(*it1, *it2);
}

TEST(set_test, iterator3) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.end();
  s21::set<int>::iterator it2 = s1.end();
  --(--it1), --(--it2);
  EXPECT_TRUE(it1 == it2);
}

TEST(set_test, iterator4) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  s21::set<int>::iterator it2 = s1.begin();
  ++(++it1), ++(++(++it2));
  EXPECT_TRUE(it1 != it2);
}

TEST(set_test, iterator5) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  s21::set<int>::iterator it2 = s1.begin();
  ++it1, ++(++(++it2));
  EXPECT_FALSE(it1 == it2);
}

TEST(set_test, iterator6) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  s21::set<int>::iterator it2 = s1.begin();
  ++(++(++it1)), ++(++(++it2));
  EXPECT_FALSE(it1 != it2);
}

TEST(set_test, iterator7) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.begin();
  EXPECT_THROW(--it1, std::invalid_argument);
}

TEST(set_test, iterator8) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int>::iterator it1 = s1.end();
  EXPECT_THROW(++it1, std::invalid_argument);
}

TEST(set_test, iterator9) {
  s21::set<int>::iterator it;
  EXPECT_THROW(++it, std::invalid_argument);
}

TEST(set_test, iterator10) {
  s21::set<int>::iterator it;
  EXPECT_THROW(--it, std::invalid_argument);
}

TEST(set_test, iterator11) {
  s21::set<std::pair<int, int>> s1{{1, 7}};
  std::set<std::pair<int, int>> s2{{1, 7}};
  s21::set<std::pair<int, int>>::iterator it1 = s1.begin();
  std::set<std::pair<int, int>>::iterator it2 = s2.begin();
  EXPECT_EQ(it1->first, it2->first);
}

TEST(set_test, empty1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, empty2) {
  s21::set<int> s1;
  std::set<int> s2;
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, size1) {
  s21::set<int> s1;
  std::set<int> s2;
  s1.insert(1);
  s2.insert(1);
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, size2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, size3) {
  s21::set<int> s1;
  std::set<int> s2;
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, max_size1) {
  s21::set<int> s1;
  std::set<int> s2;
  EXPECT_EQ(s1.max_size(), s2.max_size());
}

TEST(set_test, clear1) {
  s21::set<double> s1{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, clear2) {
  s21::set<double> s1;
  std::set<double> s2;
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, clear3) {
  s21::set<double> s1{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, insert1) {
  s21::set<double> s1{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.insert(3.0).second, s2.insert(3.0).second);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*(s1.insert(3.0).first), *(s2.insert(3.0).first));
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, insert2) {
  s21::set<double> s1{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.insert(9.0).second, s2.insert(9.0).second);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*(s1.insert(9.0).first), *(s2.insert(9.0).first));
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, insert3) {
  s21::set<double> s1{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62.5, 77.2, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.insert(943).second, s2.insert(943).second);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*(s1.insert(943).first), *(s2.insert(943).first));
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, erase1) {
  s21::set<double> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.size(), s2.size());
  s21::set<double>::iterator it1 = s1.begin();
  std::set<double>::iterator it2 = s2.begin();
  s1.erase(it1);
  s2.erase(it2);
  EXPECT_EQ(s1.size(), s2.size());
  it1 = s1.end();
  EXPECT_THROW(s1.erase(it1), std::invalid_argument);
}

TEST(set_test, erase2) {
  s21::set<double> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<double>::iterator it1 = s1.begin();
  std::set<double>::iterator it2 = s2.begin();
  s1.erase(it1);
  s2.erase(it2);
  it1 = s1.begin();
  it2 = s2.begin();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*it1, *it2);
}

TEST(set_test, erase3) {
  s21::set<double> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<double> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<double>::iterator it1 = s1.end();
  std::set<double>::iterator it2 = s2.end();
  s1.erase(--it1);
  s2.erase(--it2);
  EXPECT_EQ(s1.size(), s2.size());
  it1 = s1.begin();
  it2 = s2.begin();
  for (; it2 != s2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
}

TEST(set_test, erase4) {
  s21::set<double> s1{4};
  std::set<double> s2{4};
  s1.erase(s1.begin());
  s2.erase(s2.begin());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, erase5) {
  s21::set<double> s1{4};
  s21::set<double>::iterator it1 = s1.begin();
  s1.erase(it1);
  EXPECT_ANY_THROW(*it1);
}

TEST(set_test, swap1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11;
  std::set<int> s22;
  s1.swap(s11);
  s2.swap(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, swap2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  s21::set<int> s11{671, 5894, 720, 8096, 99};
  std::set<int> s22{671, 5894, 720, 8096, 99};
  s1.swap(s11);
  s2.swap(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, swap3) {
  s21::set<int> s1;
  std::set<int> s2;
  s21::set<int> s11;
  std::set<int> s22;
  s1.swap(s11);
  s2.swap(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

// не находит merge в библиотеке оригинального set

// TEST(set_test, merge1) {
//   s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   s21::set<int> s11{671, 5894, 720, 80396, 99};
//   std::set<int> s22{671, 5894, 720, 80396, 99};
//   s1.merge(s11);
//   s2.merge(s22);
//   EXPECT_EQ(s1.size(), s2.size());
//   EXPECT_EQ(s11.size(), s22.size());
//   auto it1 = s1.begin();
//   for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
//     EXPECT_EQ(*it1, *it2);
// }

// TEST(set_test, merge2) {
//   s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   s21::set<int> s11{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   std::set<int> s22{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   s1.merge(s11);
//   s2.merge(s22);
//   EXPECT_EQ(s1.size(), s2.size());
//   EXPECT_EQ(s11.size(), s22.size());
//   auto it1 = s1.begin();
//   for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
//     EXPECT_EQ(*it1, *it2);
// }

// TEST(set_test, merge3) {
//   s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   s21::set<int> s11{4, 73, -101, 62, 77, 158, 909, -12,
//                     3, 88, 43,   18, 5,  35,  832};
//   std::set<int> s22{4, 73, -101, 62, 77, 158, 909, -12,
//                     3, 88, 43,   18, 5,  35,  832};
//   s1.merge(s11);
//   s2.merge(s22);
//   EXPECT_EQ(s1.size(), s2.size());
//   EXPECT_EQ(s11.size(), s22.size());
//   auto it1 = s1.begin();
//   for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
//     EXPECT_EQ(*it1, *it2);
// }

// TEST(set_test, merge4) {
//   s21::set<int> s1{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
//   std::set<int> s2{77, 4, 127, -12, 456, 4, 5, 4, 34, 4, 77, 2, 0, 2, 127};
//   s21::set<int> s11{3, -121, 45, 3, 4, 7, 4, 22, -14, 92, 3, 321};
//   std::set<int> s22{3, -121, 45, 3, 4, 7, 4, 22, -14, 92, 3, 321};
//   s1.merge(s11);
//   s2.merge(s22);
//   s21::set<int>::iterator it1 = s1.begin();
//   for (std::set<int>::iterator it2 = s2.begin(); it2 != s2.end(); ++it1,
//   ++it2)
//     EXPECT_EQ(*it1, *it2);
// }

// TEST(set_test, merge5) {
//   s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   s21::set<int> s11{7, 4, 20, -9, 3, 5, -6};
//   std::set<int> s22{7, 4, 20, -9, 3, 5, -6};
//   s1.merge(s11);
//   s2.merge(s22);
//   EXPECT_EQ(s1.size(), s2.size());
//   EXPECT_EQ(s11.size(), s22.size());
//   auto it1 = s1.begin();
//   for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
//     EXPECT_EQ(*it1, *it2);
// }

// TEST(set_test, merge6) {
//   s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
//   s1.merge(s1);
//   s2.merge(s2);
//   EXPECT_EQ(s1.size(), s2.size());
//   auto it1 = s1.begin();
//   for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
//     EXPECT_EQ(*it1, *it2);
// }

TEST(set_test, find1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  std::set<int> s2{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(*(s1.find(3)), *(s2.find(3)));
}

TEST(set_test, contains1) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.contains(73), true);
}

TEST(set_test, contains2) {
  s21::set<int> s1{4, 73, -101, 62, 77, 158, 909, -12, 3, 88, 43, 18};
  EXPECT_EQ(s1.contains(7), false);
}

TEST(set_test, emplace) {
  s21::set<char> s1{'g', 'f'};
  std::set<char> s2{'g', 'f'};
  s1.emplace('7');
  s1.emplace('L');
  s1.emplace(';');
  s1.emplace('5');
  s1.emplace('e');
  s2.emplace('7');
  s2.emplace('L');
  s2.emplace(';');
  s2.emplace('5');
  s2.emplace('e');
  s21::set<char>::iterator it1 = s1.begin();
  std::set<char>::iterator it2 = s2.begin();
  EXPECT_EQ(s1.size(), s2.size());
  for (; it2 != s2.end(); ++it1, ++it2) EXPECT_EQ(*it1, *it2);
}

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА SET (END) ==========
*/

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА MAP (START) ==========
*/

TEST(map_test, constructor1) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).second, (*it2).second);
  it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).first, (*it2).first);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, constructor2) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.size(), m2.size());
  m1.insert({1, 7});
  m2.insert({1, 7});
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, constructor3) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  auto m11 = m1;
  auto m22 = m2;
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it2, ++it1)
    EXPECT_EQ((*it1).second, (*it2).second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, constructor4) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  auto m11 = std::move(m1);
  auto m22 = std::move(m2);
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it2, ++it1)
    EXPECT_EQ((*it1).second, (*it2).second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, constructor5) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  s21::map<std::string, int> m11;
  std::map<std::string, int> m22;
  m11 = std::move(m1);
  m22 = std::move(m2);
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it2, ++it1)
    EXPECT_EQ((*it1).second, (*it2).second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, at1) {
  s21::map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  for (size_t i = 1; i < m1.size(); i++) EXPECT_EQ(m1.at(i), m2.at(i));
}

TEST(map_test, at2) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  EXPECT_ANY_THROW(m1.at("hm"));
  EXPECT_ANY_THROW(m2.at("hm"));
}

TEST(map_test, at3) {
  s21::map<std::string, int> m1{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  std::map<std::string, int> m2{{"LeBron", 38},
                                {"Messi", 36},
                                {"Bradley Pitt", 59},
                                {"Tom Brady", 45},
                                {"Ryan Gosling", 42}};
  EXPECT_EQ(m1.at("Messi"), m2.at("Messi"));
}

TEST(map_test, operator_ind1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1[100], m2[100]);
  EXPECT_NO_THROW(m1[-2] = 3);
  EXPECT_NO_THROW(m2[-2] = 3);
  EXPECT_NO_THROW(m1.at(-2) = 5);
  EXPECT_NO_THROW(m2.at(-2) = 5);
  EXPECT_EQ(m1.at(-2), m2.at(-2));
}

TEST(map_test, begin1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, end1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  auto it1 = m1.end();
  auto it2 = m2.end();
  --it1, --it2;
  EXPECT_EQ((*it2).second, (*it1).second);
}

TEST(map_test, end2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  auto it1 = m1.end();
  auto it2 = m2.end();
  --it1, --it2;
  EXPECT_EQ((*it2).second, (*it1).second);
}

TEST(map_test, empty1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, empty2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, size1) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  std::pair<int, int> pair = {1, 1};
  m1.insert(pair);
  m2.insert(pair);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, size2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, size3) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, max_size1) {
  s21::map<int, int> s1;
  std::map<int, int> s2;
  EXPECT_EQ(s1.max_size(), s2.max_size());
}

TEST(map_test, clear1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, clear2) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, clear3) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, insert1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert2) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.empty(), m2.empty());
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert3) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.empty(), m2.empty());
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(3, 1).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert4) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.empty(), m2.empty());
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(3, 1).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

// TEST(map_test, insert5) {
//   s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   EXPECT_EQ(m1.empty(), m2.empty());
//   EXPECT_EQ(m1.insert_or_assign(3, 1).second, m2.insert_or_assign(3,
//   1).second); EXPECT_EQ(m1.at(3), m2.at(3)); EXPECT_EQ(m1.empty(),
//   m2.empty()); EXPECT_EQ(m1.size(), m2.size());
// }

// TEST(map_test, insert6) {
//   s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   EXPECT_EQ(m1.empty(), m2.empty());
//   EXPECT_EQ(m1.insert_or_assign(2, 1).second, m2.insert_or_assign(2,
//   1).second); EXPECT_EQ(m1.at(2), m2.at(2)); EXPECT_EQ(m1.empty(),
//   m2.empty()); EXPECT_EQ(m1.size(), m2.size());
// }

TEST(map_test, erase1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.size(), m2.size());
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_ANY_THROW(m1.erase(m1.end()));
}

TEST(map_test, erase2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swap1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  s21::map<int, int> m11;
  std::map<int, int> m22;
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swap2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  s21::map<int, int> m11{
      {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
  std::map<int, int> m22{
      {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).second, (*it2).second);
}

TEST(map_test, swap3) {
  s21::map<int, int> m1;
  std::map<int, int> m2;
  s21::map<int, int> m11;
  std::map<int, int> m22;
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it1, ++it2)
    EXPECT_EQ((*it1).second, (*it2).second);
}

// TEST(map_test, merge1) {
//   s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   s21::map<int, int> m11{
//       {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
//   std::map<int, int> m22{
//       {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
//   m1.merge(m11);
//   m2.merge(m22);
//   EXPECT_EQ(m1.size(), m2.size());
//   EXPECT_EQ(m11.size(), m22.size());
//   auto it1 = m1.begin();
//   for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
//     EXPECT_EQ((*it1).second, (*it2).second);
// }

// TEST(map_test, merge2) {
//   s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   s21::map<int, int> m11{
//       {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
//   std::map<int, int> m22{
//       {15, 44}, {265, 2904}, {243508, 24}, {22435, 7}, {7, 45}};
//   m1.merge(m11);
//   m2.merge(m22);
//   EXPECT_EQ(m1.size(), m2.size());
//   EXPECT_EQ(m11.size(), m22.size());
//   auto it1 = m1.begin();
//   for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
//     EXPECT_EQ((*it1).second, (*it2).second);
// }

// TEST(map_test, merge3) {
//   s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   std::map<int, int> m2{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
//   s21::map<int, int> m11{{15, 44}, {265, 2904}, {243508, 24}, {22435, 7},
//                          {7, 45},  {56, 0},     {4, 0},       {542, 5}};
//   std::map<int, int> m22{{15, 44}, {265, 2904}, {243508, 24}, {22435, 7},
//                          {7, 45},  {56, 0},     {4, 0},       {542, 5}};
//   m1.merge(m11);
//   m2.merge(m22);
//   EXPECT_EQ(m1.size(), m2.size());
//   EXPECT_EQ(m11.size(), m22.size());
//   auto it1 = m1.begin();
//   for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
//     EXPECT_EQ((*it1).second, (*it2).second);
// }

TEST(map_test, contains1) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.contains(44), true);
}

TEST(map_test, contains2) {
  s21::map<int, int> m1{{7, 1}, {2, 2}, {100, 99}, {44, -19}, {1234, 4321}};
  EXPECT_EQ(m1.contains(0), false);
}

TEST(map_test, emplace) {
  s21::map<std::string, int> m1{{"LeBron", 38}, {"Messi", 36}};
  std::map<std::string, int> m2{{"LeBron", 38}, {"Messi", 36}};
  m1.emplace("Bradley Pitt", 59);
  m1.emplace("LeBron", 38);
  m1.emplace("Ryan Gosling", 42);
  m1.emplace("Messi", 36);
  m1.emplace("Ryan Gosling", 42);
  m2.emplace("Bradley Pitt", 59);
  m2.emplace("LeBron", 38);
  m2.emplace("Ryan Gosling", 42);
  m2.emplace("Messi", 36);
  m2.emplace("Ryan Gosling", 42);
  s21::map<std::string, int>::iterator it1 = m1.begin();
  std::map<std::string, int>::iterator it2 = m2.begin();
  EXPECT_EQ(m1.size(), m2.size());
  for (; it2 != m2.end(); ++it1, ++it2) EXPECT_EQ((*it1).second, (*it2).second);
}

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА MAP (END) ==========
*/

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА QUEUE (START) ==========
*/

template <typename value_type>
bool compare_queues(s21::queue<value_type> my_queue,
                    std::queue<value_type> std_queue) {
  bool result = true;
  if (my_queue.size() == std_queue.size()) {
    while (!my_queue.empty() && !std_queue.empty()) {
      if (my_queue.front() != std_queue.front()) {
        result = false;
        break;
      }
      my_queue.pop();
      std_queue.pop();
    }
  } else {
    result = false;
  }
  return result;
}

TEST(QueueTest, CompareQueues) {
  s21::queue<int> my_queue{1, 3, 10, -5, 20};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(3);
  std_queue.push(10);
  std_queue.push(-5);
  std_queue.push(20);
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
  std_queue.push(20);
  EXPECT_FALSE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, CompareQueues_2) {
  s21::queue<int> my_queue{1, 3, 10, -5, 20};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(3);
  std_queue.push(10);
  std_queue.push(-5);
  std_queue.push(100);
  EXPECT_FALSE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, DefaultConstructor) {
  s21::queue<int> my_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(my_queue.size(), 0);
  EXPECT_TRUE(my_queue.empty());
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor) {
  s21::queue<int> my_queue{1, 2, 3, 7, 9};
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor_2) {
  std::initializer_list<int> b;
  s21::queue<int> my_queue{b};
  std::queue<int> std_queue{b};
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, CopyConstructor) {
  s21::queue<int> my_queue{1, 2, 3, 7, 9};
  s21::queue<int> my_queue_copy(my_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, CopyConstructorEmpty) {
  s21::queue<int> my_queue;
  s21::queue<int> my_queue_copy(my_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveConstructor) {
  s21::queue<int> my_queue{1, 2, 3, 7, 20};
  //   s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move(std::move(my_queue));
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  //   std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queues(my_queue_move, std_queue_move));
}

TEST(QueueTest, MoveConstructorEmpty) {
  s21::queue<int> my_queue;
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move(std::move(my_queue));
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queues(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveAssignmentOperator) {
  s21::queue<int> my_queue{1, 2, 3, 7, 20};
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move = std::move(my_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_move, std_queue_move));
}

TEST(QueueTest, MoveAssignmentOperatorEmpty) {
  s21::queue<int> my_queue;
  s21::queue<int> my_queue_copy(my_queue);
  s21::queue<int> my_queue_move = std::move(my_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queues(my_queue_move, std_queue_move));
}

TEST(QueueTest, Front) {
  s21::queue<int> my_queue{99, 2, 3, 4, 5};
  std::initializer_list<int> il = {99, 1, 3, 7, 20};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.front(), std_queue.front());
}

TEST(QueueTest, Back) {
  s21::queue<int> my_queue{1, 2, 3, 3, 4, 99};
  std::initializer_list<int> il = {99, 1, 3, 5, 4, 7, 99};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.back(), std_queue.back());
}

TEST(QueueTest, Empty) {
  s21::queue<int> my_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(my_queue.empty(), std_queue.empty());
  my_queue.push(2354);
  std_queue.push(2354);
  EXPECT_EQ(my_queue.empty(), std_queue.empty());
}

TEST(QueueTest, Size) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.size(), std_queue.size());
}

TEST(QueueTest, Push) {
  s21::queue<int> my_queue;
  std::queue<int> std_queue;
  my_queue.push(627);
  std_queue.push(627);
  my_queue.push(2354);
  std_queue.push(2354);
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
}

TEST(QueueTest, Pop) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  my_queue.pop();
  my_queue.pop();
  std_queue.pop();
  std_queue.pop();
  EXPECT_TRUE(compare_queues(my_queue, std_queue));
  EXPECT_EQ(my_queue.front(), 3);
}

TEST(QueueTest, Swap) {
  s21::queue<int> my_queue1{1, 2, 3, 4, 5};
  s21::queue<int> my_queue2{6, 7, 8, 9, 10, 11};
  my_queue1.swap(my_queue2);

  std::initializer_list<int> il1 = {1, 2, 3, 4, 5};
  std::initializer_list<int> il2 = {6, 7, 8, 9, 10, 11};
  std::queue<int> std_queue1{il1};
  std::queue<int> std_queue2{il2};
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queues(my_queue1, std_queue1));
  EXPECT_TRUE(compare_queues(my_queue2, std_queue2));
}

TEST(QueueTest, Swap_2) {
  s21::queue<int> my_queue1{1, 2, 99, 4, 242};
  s21::queue<int> my_queue2;
  my_queue1.swap(my_queue2);

  std::initializer_list<int> il = {1, 2, 99, 4, 242};
  std::queue<int> std_queue1{il};
  std::queue<int> std_queue2;
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queues(my_queue1, std_queue1));
  EXPECT_TRUE(compare_queues(my_queue2, std_queue2));
}

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА QUEUE (END) ==========
*/

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА LIST (START) ==========
*/

TEST(ListConstructor, Default) {
  std::list<int> list;
  s21::list<int> s21_list;

  ASSERT_EQ(s21_list.empty(), list.empty());
}

TEST(ListConstructor, Sized) {
  s21::list<int> s21_list(3);

  ASSERT_EQ(s21_list.size(), 3);

  for (auto& item : s21_list) ASSERT_EQ(item, 0);
}

TEST(ListConstructor, InitializerList) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.cbegin();

  ASSERT_EQ(s21_list.size(), list.size());

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListConstructor, Copy) {
  std::list<int> list{1, 2, 3}, copy(list);
  s21::list<int> s21_list{1, 2, 3}, s21_copy(s21_list);
  auto it = copy.cbegin();

  ASSERT_EQ(s21_copy.size(), copy.size());

  for (auto& item : s21_copy) ASSERT_EQ(item, *(it++));
}

TEST(ListConstructor, Move) {
  std::list<int> list{1, 2, 3}, moved(std::move(list));
  s21::list<int> s21_list{1, 2, 3}, s21_moved(std::move(s21_list));
  auto it = moved.cbegin();

  ASSERT_EQ(s21_list.empty(), list.empty());
  ASSERT_EQ(s21_moved.size(), moved.size());

  for (auto& item : s21_moved) ASSERT_EQ(item, *(it++));
}

TEST(ListConstructor, MoveOperator) {
  std::list<int> list{1, 2, 3}, moved;
  s21::list<int> s21_list{1, 2, 3}, s21_moved;

  moved = std::move(list);
  s21_moved = std::move(s21_list);

  auto it = moved.cbegin();

  ASSERT_EQ(s21_list.empty(), list.empty());
  ASSERT_EQ(s21_moved.size(), moved.size());

  for (auto& item : s21_moved) ASSERT_EQ(item, *(it++));
}

TEST(ListAccessors, Front) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};

  ASSERT_EQ(s21_list.front(), list.front());
}

// TEST(ListAccessors, FrontEmptyList) {
//   std::list<int> list;
//   s21::list<int> s21_list;

//   EXPECT_THROW(s21_list.front(), std::logic_error);
// }

TEST(ListAccessors, Back) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};

  ASSERT_EQ(s21_list.back(), list.back());
}

// TEST(ListAccessors, BackEmptyList) {
//   std::list<int> list;
//   s21::list<int> s21_list;

//   EXPECT_THROW(s21_list.back(), std::logic_error);
// }

TEST(ListIterator, DerefOperator) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.begin();
  auto s21_it = s21_list.begin();

  ASSERT_EQ(*s21_it, *it);
}

TEST(ListIterator, PlusPlusOperator) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.begin();
  auto s21_it = s21_list.begin();

  it++;
  s21_it++;

  ASSERT_EQ(*s21_it, *it);
}

TEST(ListIterator, ForInLoop) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.begin();

  for (auto& item : list) EXPECT_EQ(item, *(it++));
}

TEST(ListIterator, ForLoop) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.begin();

  for (auto s21_it = s21_list.begin(); s21_it != s21_list.end(); s21_it++)
    EXPECT_EQ(*s21_it, *(it++));
}

TEST(ListIterator, Mutations) {
  std::list<int> list{2, 4, 6};
  s21::list<int> s21_list{1, 2, 3};
  auto it = list.begin();

  for (auto& item : list) item *= 2;
  for (auto& item : list) ASSERT_EQ(item, *(it++));
}

// TEST(ListConstIterator, DerefOperator) {
//   std::list<int> list{1, 2, 3};
//   s21::list<int> s21_list{1, 2, 3};
//   auto it = list.cbegin();
//   auto s21_it = s21_list.cbegin();

//   ASSERT_EQ(*s21_it, *it);
// }

// TEST(ListConstIterator, PlusPlusOperator) {
//   std::list<int> list{1, 2, 3};
//   s21::list<int> s21_list{1, 2, 3};
//   auto it = list.cbegin();
//   auto s21_it = s21_list.cbegin();

//   it++;
//   s21_it++;

//   ASSERT_EQ(*s21_it, *it);
// }

// TEST(ListConstIterator, ForLoop) {
//   std::list<int> list{1, 2, 3};
//   s21::list<int> s21_list{1, 2, 3};
//   auto it = list.cbegin();

//   for (auto s21_it = s21_list.cbegin(); s21_it != s21_list.cend(); s21_it++)
//     EXPECT_EQ(*s21_it, *(it++));
// }

TEST(ListCapacity, Empty) {
  std::list<int> list;
  s21::list<int> s21_list;

  ASSERT_EQ(s21_list.empty(), list.empty());
}

TEST(ListCapacity, NotEmpty) {
  std::list<int> list{1, 2};
  s21::list<int> s21_list{1, 2};

  ASSERT_EQ(s21_list.empty(), list.empty());
}

TEST(ListCapacity, SizeEmpty) {
  std::list<int> list;
  s21::list<int> s21_list;

  ASSERT_EQ(s21_list.size(), list.size());
}

TEST(ListCapacity, SizeOneItem) {
  std::list<int> list{1};
  s21::list<int> s21_list{1};

  ASSERT_EQ(s21_list.size(), list.size());
}

TEST(ListCapacity, SizeFiveItems) {
  std::list<int> list{1, 2, 3, 4, 5};
  s21::list<int> s21_list{1, 2, 3, 4, 5};

  ASSERT_EQ(s21_list.size(), list.size());
}

TEST(ListCapacity, MaxSize) {
  std::list<int> list;
  s21::list<int> s21_list;

  ASSERT_EQ(s21_list.max_size(), list.max_size());
}

TEST(ListModifiers, Clear) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2, 3};

  list.clear();
  s21_list.clear();

  ASSERT_EQ(s21_list.empty(), list.empty());
}

TEST(ListModifiers, ClearEmpty) {
  std::list<int> list;
  s21::list<int> s21_list;

  list.clear();
  s21_list.clear();

  ASSERT_EQ(s21_list.empty(), list.empty());
}

TEST(ListModifiers, InsertEmpty) {
  s21::list<int> s21_list;

  auto s21_res = s21_list.insert(s21_list.begin(), 0);

  ASSERT_EQ(s21_list.front(), 0);
  ASSERT_EQ(*s21_res, 0);
}

TEST(ListModifiers, InsertAtStart) {
  std::list<int> list{0, 1, 2};
  s21::list<int> s21_list{1, 2};
  auto it = list.begin();

  auto s21_res = s21_list.insert(s21_list.begin(), 0);

  ASSERT_EQ(s21_list.front(), 0);
  ASSERT_EQ(*s21_res, 0);

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, InsertAtEnd) {
  std::list<int> list{1, 2, 3};
  s21::list<int> s21_list{1, 2};
  auto it = list.begin();
  auto s21_iter = s21_list.begin();

  s21_iter++;
  s21_iter++;

  auto s21_res = s21_list.insert(s21_iter, 3);

  ASSERT_EQ(s21_list.back(), 3);
  ASSERT_EQ(*s21_res, 3);

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

// TEST(ListModifiers, EraseAtStart) {
//   s21::list<int> list{1, 2};
//   list.erase(list.begin());

//   ASSERT_TRUE(list.empty());
// }

// TEST(ListModifiers, EraseAfterFirst) {
//   s21::list<int> list{1, 2, 3, 4};
//   list.erase(++list.begin());

//   ASSERT_EQ(list.size(), 1);
//   ASSERT_EQ(list.front(), 1);
// }

TEST(ListModifiers, PushBackEmpty) {
  s21::list<int> s21_list;

  s21_list.push_back(0);

  ASSERT_EQ(s21_list.back(), 0);
}

TEST(ListModifiers, PushBack) {
  s21::list<int> s21_list{1, 2, 3};

  s21_list.push_back(4);

  ASSERT_EQ(s21_list.back(), 4);
}

TEST(ListModifiers, PopBackEmpty) {
  s21::list<int> s21_list;

  s21_list.pop_back();

  ASSERT_TRUE(s21_list.empty());
}

// TEST(ListModifiers, PopBackOneElement) {
//   s21::list<int> s21_list{1};

//   s21_list.pop_back();

//   ASSERT_TRUE(s21_list.empty());
// }

// TEST(ListModifiers, PopBackFiveElements) {
//   std::list<int> list{1, 2, 3, 4};
//   s21::list<int> s21_list{1, 2, 3, 4, 5};
//   auto it = list.begin();

//   s21_list.pop_back();

//   ASSERT_EQ(s21_list.size(), 4);

//   for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
// }

TEST(ListModifiers, PushFrontEmpty) {
  s21::list<int> s21_list;

  s21_list.push_front(0);

  ASSERT_EQ(s21_list.front(), 0);
}

TEST(ListModifiers, PushFront) {
  s21::list<int> s21_list{1, 2, 3};

  s21_list.push_front(0);

  ASSERT_EQ(s21_list.front(), 0);
}

TEST(ListModifiers, PopFrontEmpty) {
  s21::list<int> s21_list;

  s21_list.pop_front();

  ASSERT_TRUE(s21_list.empty());
}

TEST(ListModifiers, PopFrontOneElement) {
  s21::list<int> s21_list{1};

  s21_list.pop_front();

  ASSERT_TRUE(s21_list.empty());
}

TEST(ListModifiers, PopFrontFiveElements) {
  std::list<int> list{2, 3, 4, 5};
  s21::list<int> s21_list{1, 2, 3, 4, 5};
  auto it = list.begin();

  s21_list.pop_front();

  ASSERT_EQ(s21_list.size(), 4);

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, SwapEmpty) {
  std::list<int> list{4, 5, 6, 7};
  s21::list<int> s21_list, s21_swap{4, 5, 6, 7};
  auto it = list.begin();

  s21_list.swap(s21_swap);

  ASSERT_TRUE(s21_swap.empty());
  ASSERT_EQ(s21_list.size(), list.size());
  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, Swap) {
  std::list<int> list{1, 2, 3}, swap{4, 5, 6, 7};
  s21::list<int> s21_list{1, 2, 3}, s21_swap{4, 5, 6, 7};

  list.swap(swap);
  s21_list.swap(s21_swap);

  auto it = list.begin();
  auto swap_it = swap.begin();

  ASSERT_EQ(s21_list.size(), list.size());
  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));

  ASSERT_EQ(s21_swap.size(), swap.size());
  for (auto& item : s21_swap) ASSERT_EQ(item, *(swap_it++));
}

TEST(ListModifiers, Merge) {
  s21::list<int> list{2, 5}, merge{3, 1, 4};
  s21::list<int> s21_list{2, 5}, s21_merge{3, 1, 4};

  list.merge(merge);
  s21_list.merge(s21_merge);

  auto it = list.begin();
  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

// TEST(ListModifiers, Splice) {
//   s21::list<int> s21_list{1, 2, 3}, s21_splice{-1, 0}, s21_res{-1, 0, 1, 2,
//   3}; auto it = s21_res.begin();

//   s21_list.splice(s21_list.cbegin(), s21_splice);

//   ASSERT_EQ(s21_list.size(), 5);
//   for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
// }

TEST(ListModifiers, Reverse) {
  s21::list<int> s21_list{1, 2, 3}, s21_res{3, 2, 1};
  auto it = s21_res.begin();

  s21_list.reverse();

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, Unique) {
  s21::list<int> s21_list{1, 1, 2, 3, 3}, s21_res{1, 2, 3};
  auto it = s21_res.begin();

  s21_list.unique();

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

TEST(ListModifiers, Sort) {
  s21::list<int> s21_list{2, 1, 5, 4, 3}, s21_sorted{1, 2, 3, 4, 5};
  auto it = s21_sorted.begin();

  s21_list.sort();

  for (auto& item : s21_list) ASSERT_EQ(item, *(it++));
}

/*
    ========== ТЕСТЫ КОНТЕЙНЕРА LIST (END) ==========
*/


int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
