#include <iostream>
#include "duplicate.hpp"

int main() {
  
  int list[]{ 6, 3, 2, 5, 8, 3, 1, 2, -1 };
  
  int size = sizeof(list)/sizeof(int);
    
  bool answer = ths::has_duplicate(list, list + size);

  if (answer != true) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer == true);
}
