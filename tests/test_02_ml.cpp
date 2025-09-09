#include <iostream>
#include "questao_1/minimum_local.hpp"

bool less_than(int a, int b) {
  return a < b;
}

int main() {
  
  int list[]{19, 12, 11, 10, 9, 8};
  
  int list_size = sizeof(list)/sizeof(int);
    
  int *answer = ths::local_min(list, list + list_size, less_than);

  if (answer != &list[5]) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer == &list[5]);
}
