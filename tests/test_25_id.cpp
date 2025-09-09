#include <iostream>
#include "questao_7/identity.hpp"

bool less_than(int a, int b) {
  return a < b;
}

int main() {
  
  int list[]{ 0, 3, 10, 11, 12, 13, 14, 15, 17, 99, 999, 9999 };
  
  int size = sizeof(list)/sizeof(int);
    
  int *answer = ths::find_identity(list, list + size, less_than);

  if (answer - list != *answer) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer - list == *answer);
}
