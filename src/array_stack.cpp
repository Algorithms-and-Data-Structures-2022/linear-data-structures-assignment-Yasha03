#include "assignment/array_stack.hpp"

#include <algorithm>  // copy, fill
#include <stdexcept>  // invalid_argument (НЕЛЬЗЯ ИСПОЛЬЗОВАТЬ)

namespace assignment {

  ArrayStack::ArrayStack(int capacity) {
    if (capacity <= 0) {
      throw std::invalid_argument("capacity is not positive");
    }
    size_ = 0;
    capacity_ = capacity;
    data_ = new int[capacity_];
    std::fill(&data_[0], data_ + capacity, 0);
  }

  ArrayStack::~ArrayStack() {
    size_ = 0;
    capacity_ = 0;
    delete[] data_;
    data_ = nullptr;
  }

  void ArrayStack::Push(int value) {
    if(size() >= capacity()){
      Resize(capacity()+kCapacityGrowthCoefficient);
    }
    data_[size_] = value;
    size_++;
  }

  bool ArrayStack::Pop() {
    if (size() == 0) {
      return false;
    }
    data_[size()-1] = 0;
    size_--;
    return true;
  }

  void ArrayStack::Clear() {
      size_ = 0;
  }

  std::optional<int> ArrayStack::Peek() const {
    if (size() == 0) {
      return std::nullopt;
    }
    return data_[size()-1];
  }

  bool ArrayStack::IsEmpty() const {
    return size_ == 0;
  }

  int ArrayStack::size() const {
    return size_;
  }

  int ArrayStack::capacity() const {
    return capacity_;
  }

  bool ArrayStack::Resize(int new_capacity) {
    if(new_capacity <= capacity()){
      return false;
    }
    int oldCapacity = capacity();
    capacity_ = new_capacity;
    int* newArr;
    newArr = new int[capacity()];
    for (int i = 0; i < oldCapacity; ++i) {
      newArr[i] = data_[i];
    }
    for (int i = oldCapacity; i < capacity_; ++i) {
      newArr[i] = 0;
    }
    data_ = newArr;
    return true;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  ArrayStack::ArrayStack(const std::vector<int>& values, int capacity) {

    size_ = static_cast<int>(values.size());
    capacity_ = capacity;

    data_ = new int[capacity]{};

    std::copy(values.data(), values.data() + size_, data_);
  }

  std::vector<int> ArrayStack::toVector(std::optional<int> size) const {

    if (capacity_ == 0 || data_ == nullptr) {
      return {};
    }

    if (size.has_value()) {
      return {data_, data_ + size.value()};
    }

    return {data_, data_ + capacity_};
  }

}  // namespace assignment
