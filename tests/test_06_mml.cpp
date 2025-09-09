#include <iostream>
#include "questao_2/min_local_matrix.hpp"

bool less_than(int a, int b) {
  return a < b;
}

int main() {
  
  int matrix[]{11, 5, 12,
               6, -10, 9,
               13, 4, 99};
  
  int size1 = 3;
  int size2 = 3;
    
  int *answer = ths::local_min_m(matrix, {size1, size2}, less_than);

  if (answer != &matrix[4]) {
    std::cout << "Failed\n";
  } else std::cout << "All ok.";
  return static_cast<int>(answer == &matrix[4]);
}
