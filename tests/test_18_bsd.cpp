#include <iostream>
#include "bin_search_dupl.hpp"

bool less_than(int a, int b) {
  return a < b;
}

int main() {
  
  int list[]{ 1, 3, 10, 10, 10, 10, 10, 10, 12, 99, 999, 9999 };
  
  int size = sizeof(list)/sizeof(int);
    
  int *answer = ths::bin_search_dupl(list, list + size, 10, less_than);

  if (answer != &list[2]) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer == &list[2]);
}
