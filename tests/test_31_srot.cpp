#include <iostream>
#include "questao_9/sorted_rotated.hpp"

bool less_than(int n1, int n2) {
  return n1 < n2;
}

int main() {
  
  int list[]{ 30, 31, 33, 35, 91, 93, 95, 97, 910, 912, 920 };
  
  int size = sizeof(list)/sizeof(int);
    
  int *answer = ths::bsearch_rot(list, list + size, 910, less_than);

  if (answer != (list + 8)) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer == (list + 8));
}
