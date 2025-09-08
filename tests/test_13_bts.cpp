#include <iostream>
#include "bitonic_search.hpp"

bool less_than(int a, int b) {
  return a < b;
}

int main() {
  
  int list[]{ 1, 3, 5, 7, 8, 6, 4, 2, 0 };
  
  int size = sizeof(list)/sizeof(int);
    
  int *answer = ths::bitonic_search(list, list + size, 13, less_than);

  if (answer != list + size) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer == list + size);
}
