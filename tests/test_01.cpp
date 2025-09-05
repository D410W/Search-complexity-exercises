#include <iostream>
#include "math_lib.hpp"

int main() {
  if (mb::add(1, 3) != 4) {
    std::cout << "Failed\n";
  }
  std::cout << "All ok.";
  return static_cast<int>(mb::add(1, 3) == 4);
}
