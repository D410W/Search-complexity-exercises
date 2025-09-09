#include <iostream>
#include "questao_3/bitonic_search.hpp"

bool less_than(int a, int b) {
  return a < b;
}

int main() {
  
  int list[]{};
  
  int size = sizeof(list)/sizeof(int);
    
  int *answer = ths::bitonic_search(list, list + size, 99999, less_than);

  if (answer != list) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer == list);
}
