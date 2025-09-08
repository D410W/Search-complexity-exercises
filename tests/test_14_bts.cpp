#include <iostream>
#include "bitonic_search.hpp"

bool less_than(int a, int b) {
  return a < b;
}

int main() {
  
  int list[]{ 1, 3, 5, 7, 8, 10, 12, 14, 15, 16 };
  
  int size = sizeof(list)/sizeof(int);
    
  int *answer = ths::bitonic_search(list, list + size, 1, less_than);

  if (answer != &list[0]) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer == &list[0]);
}
