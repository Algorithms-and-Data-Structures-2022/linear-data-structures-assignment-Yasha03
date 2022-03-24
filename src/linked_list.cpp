#include "assignment/linked_list.hpp"

namespace assignment {

  LinkedList::~LinkedList() {

    // эквивалентно очистке списка
    LinkedList::Clear();
  }

  void LinkedList::Add(int value) {
    Node* newNode = new Node(value, nullptr);
    if (size() == 0) {
      front_ = newNode;
      back_ = newNode;
    } else {
      (*back_).next = newNode;
      back_ = newNode;
    }
    size_++;
  }

  bool LinkedList::Insert(int index, int value) {
    if (index == size()) {
      Add(value);
      return true;
    }
    if(index < 0 || index > size()){
      return false;
    }
    if (index == 0) {
      front_ = new Node(value, front_);
      if (size() == 0) {
        back_ = front_;
      }
      size_++;
      return true;
    }

    Node* node = FindNode(index - 1);
    Node* valueNode = new Node(value, node->next);
    node->next = valueNode;
    size_++;
    return true;
  }

  bool LinkedList::Set(int index, int new_value) {
    if(index < 0 || index >= size()){
      return false;
    }
    Node* findElem = FindNode(index);
    findElem->value = new_value;
    return true;
  }

  std::optional<int> LinkedList::Remove(int index) {
    if (index < 0 || index >= size()) {
      return std::nullopt;
    }
    int del = FindNode(index)->value;
    if(index == 0){
      front_=(front_->next);
    } else{
      FindNode(index-1)->next= FindNode(index)->next;
    }
    size_--;
    return del;
  }

  void LinkedList::Clear() {
    Node* node = front_;
    for (int i = 0; i < size(); i++){
      Node* node2 = node->next;
      delete node;
      node = node2;
    }
    front_ = nullptr;
    back_ = nullptr;
    size_ = 0;
  }

  std::optional<int> LinkedList::Get(int index) const {
    if(index < 0 || index >= size()){
      return std::nullopt;
    }
    Node* node = front_;
    for (int i = 0; i < index; i++) {
      node = node->next;
    }
    return node->value;
  }

  std::optional<int> LinkedList::IndexOf(int value) const {
    Node* node = front_;
    for (int i = 0; i < size(); ++i) {
      if(node->value == value) return i;
      node = node->next;
    }
    return std::nullopt;
  }

  bool LinkedList::Contains(int value) const {
    return !(IndexOf(value) == std::nullopt);
  }

  bool LinkedList::IsEmpty() const {
    return size() == 0;
  }

  int LinkedList::size() const {
    return size_;
  }

  std::optional<int> LinkedList::front() const {
    return front_->value;
  }

  std::optional<int> LinkedList::back() const {
    return back_->value;
  }

  Node* LinkedList::FindNode(int index) const {
    if(index < 0 || index >= size()){
      return nullptr;
    }
    Node* node = front_;
    for (int i = 0; i < index; i++) {
      node = node->next;
    }
    return node;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  LinkedList::LinkedList(const std::vector<int>& values) {

    if (values.empty()) {
      return;
    }

    auto* curr_node = new Node(values.front());
    front_ = curr_node;

    for (int index = 1; index < values.size() - 1; ++index) {
      curr_node->next = new Node(values[index]);
      curr_node = curr_node->next;
    }

    if (values.size() == 1) {
      back_ = front_;
    } else {
      curr_node->next = new Node(values.back());
      back_ = curr_node->next;
    }

    size_ = static_cast<int>(values.size());
  }

  std::vector<int> LinkedList::toVector() const {

    if (front_ == nullptr || size_ == 0) {
      return {};
    }

    std::vector<int> array;
    array.reserve(size_);

    for (auto* node = front_; node != nullptr; node = node->next) {
      array.push_back(node->value);
    }

    return array;
  }

}  // namespace assignment