#include <iostream>
#include "questao_6/flr_ceil_range.hpp"

bool less_than(int a, int b) {
  return a < b;
}

int main() {
  
  int list[]{ 1, 3, 10, 10, 10, 10, 10, 10, 12, 99, 999, 9999 };
  
  int size = sizeof(list)/sizeof(int);
    
  std::pair<int, int> answer = ths::flr_ceil_range(list, list + size, 2, less_than);

  if (answer != std::pair<int, int>{1, 3}) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer == std::pair<int, int>{1, 3});
}
