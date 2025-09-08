#include <iostream>
#include "minimum_local.hpp"

bool less_than(int a, int b) {
  return a < b;
}

int main() {
  
  int list[]{1, 2, 3, 4, 5, 6, 8};
  
  int list_size = sizeof(list)/sizeof(int);
    
  int *answer = ths::local_min(list, list + list_size, less_than);

  if (answer != &list[0]) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer == &list[0]);
}
