#include <iostream>
#include "math_lib.hpp"

int main() {
  if (mb::add(0, 2) != 2) {
    std::cout << "failed.\n";
  }
  std::cout << "All ok.\n";

  return static_cast<int>(mb::add(0, 0) == 4);
}
