#include "assignment/dynamic_array.hpp"

#include <algorithm>  // copy, fill
#include <stdexcept>  // invalid_argument (НЕЛЬЗЯ ИСПОЛЬЗОВАТЬ)

namespace assignment {

  DynamicArray::DynamicArray(int capacity) {

    // выбрасываем ошибку, если указана неположительная емкость массива
    if (capacity <= 0) {
      throw std::invalid_argument("capacity is not positive");
    }
    size_ = 0;
    capacity_ = capacity;
    data_ = new int[capacity_];
    std::fill(&data_[0], data_ + capacity, 0);
  }

  DynamicArray::~DynamicArray() {
    size_ = 0;
    capacity_ = 0;
    delete[] data_;
    data_ = nullptr;
  }

  void DynamicArray::Add(int value) {
    if(size() >= capacity()){
      Resize(capacity()+kCapacityGrowthCoefficient);
    }
    data_[size_] = value;
    size_++;
  }

  bool DynamicArray::Insert(int index, int value) {
    if(index < 0 || index > size()){
      return false;
    }
    if(size() >= capacity()){
      Resize(capacity()+kCapacityGrowthCoefficient);
    }

    int oldElem = value;
    int c = 0;
    for (int i = index + 1; i < capacity() + 1; ++i) {
      c = data_[i];
      data_[i] = oldElem;
      oldElem = c;
    }
    data_[index] = value;
    size_++;
  }

  bool DynamicArray::Set(int index, int new_value) {
    // Write your code here ...
    return false;
  }

  std::optional<int> DynamicArray::Remove(int index) {
    // Write your code here ...
    return std::nullopt;
  }

  void DynamicArray::Clear() {
    // Write your code here ...
  }

  std::optional<int> DynamicArray::Get(int index) const {
    if(index >= 0 && index < size()){
      return data_[index];
    }
    return std::nullopt;
  }

  std::optional<int> DynamicArray::IndexOf(int value) const {
    // Write your code here ...
    return std::nullopt;
  }

  bool DynamicArray::Contains(int value) const {
    return false;
  }

  bool DynamicArray::IsEmpty() const {
    return size() == 0;
  }

  int DynamicArray::size() const {
    return size_;
  }

  int DynamicArray::capacity() const {
    return capacity_;
  }

  bool DynamicArray::Resize(int new_capacity) {
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
  DynamicArray::DynamicArray(const std::vector<int>& values, int capacity) {

    size_ = static_cast<int>(values.size());
    capacity_ = capacity;

    data_ = new int[capacity]{};

    std::copy(values.data(), values.data() + size_, data_);
  }

  std::vector<int> DynamicArray::toVector(std::optional<int> size) const {

    if (capacity_ == 0 || data_ == nullptr) {
      return {};
    }

    if (size.has_value()) {
      return {data_, data_ + size.value()};
    }

    return {data_, data_ + capacity_};
  }

}  // namespace assignment