#include <iostream>
#include "questao_9/sorted_rotated.hpp"

bool less_than(int n1, int n2) {
  return n1 < n2;
}

int main() {
  
  int list[]{ 30, 31, 33, 35, 1, 3, 5, 7, 10, 12, 20 };
  
  int size = sizeof(list)/sizeof(int);
    
  int *answer = ths::bsearch_rot(list, list + size, 33, less_than);

  if (answer != (list + 2)) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer == (list + 2));
}
