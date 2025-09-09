#include <iostream>
#include "questao_4/bin_search_dupl.hpp"

bool less_than(int a, int b) {
  return a < b;
}

int main() {
  
  int list[]{};
  
  int size = sizeof(list)/sizeof(int);
    
  int *answer = ths::bin_search_dupl(list, list + size, 10, less_than);

  if (answer != list) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer == list);
}
