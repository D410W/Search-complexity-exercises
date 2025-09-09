#include <iostream>
#include "questao_8/duplicate.hpp"

int main() {
  
  int list[]{ 6, 3, 2, 5, 8, 70, 1, 20, -1 };
  
  int size = sizeof(list)/sizeof(int);
    
  bool answer = ths::has_duplicate(list, list + size);

  if (answer != false) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer == false);
}
