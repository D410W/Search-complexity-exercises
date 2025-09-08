#include <iostream>
#include "min_local_matrix.hpp"

bool less_than(int a, int b) {
  return a < b;
}

int main() {
  
  int matrix[]{ 9, 8, 7,
                6, 5, 4,
                3, 2, 0};
  
  int size1 = 3;
  int size2 = 3;
    
  int *answer = ths::local_min_m(matrix, {size1, size2}, less_than);

  if (answer != &matrix[8]) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer == &matrix[8]);
}
