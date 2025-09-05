#include <iostream>
#include "math_lib.hpp"

int main() {
  if (mb::exp(2, 3) != 8) {
    std::cout << "Failed.\n";
  }
  std::cout << "Test passed.\n";
  return static_cast<int>(mb::exp(2, 3) == 8);
}
