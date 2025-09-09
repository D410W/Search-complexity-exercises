#include <iostream>
#include "questao_4/bin_search_dupl.hpp"

bool less_than(int a, int b) {
  return a < b;
}

int main() {
  
  int list[]{ 3, 3, 3, 3, 3, 10, 10, 12, 99, 999, 9999 };
  
  int size = sizeof(list)/sizeof(int);
    
  int *answer = ths::bin_search_dupl(list, list + size, 3, less_than);

  if (answer != &list[0]) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer == &list[0]);
}
