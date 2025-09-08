#include <iostream>
#include "bitonic_search.hpp"

bool less_than(int a, int b) {
  return a < b;
}

int main() {
  
  int list[]{ 3, 2, 1, 0, -1, -2, -3 };
  
  int size = sizeof(list)/sizeof(int);
    
  int *answer = ths::bitonic_search(list, list + size, 2, less_than);
      
  if (answer != &list[1]) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  
  return static_cast<int>(answer == &list[1]);
}
