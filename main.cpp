#include <iostream>  // cout

#include "assignment/dynamic_array.hpp"  // DynamicArray
#include "assignment/linked_list.hpp"    // LinkedList
#include "assignment/array_stack.hpp"    // ArrayStack
#include "assignment/linked_queue.hpp"   // LinkedQueue

using std::cout;

int main(int argc, char **argv) {

  // Пример. Создание пустого динамического массива.
  assignment::DynamicArray array;
  array.Add(5);array.Add(3);array.Add(2);array.Add(3);array.Add(87);array.Add(1);array.Add(7);array.Add(12);
  array.Add(7);array.Add(6);array.Add(11);array.Add(9);
  std::optional<int> elem = array.Get(11);
  int elem2 = elem.value();
  printf("result: %d\n", elem2);
  cout << array.capacity();
  cout << "\nWrite your code here...\n";

  return 0;
}
