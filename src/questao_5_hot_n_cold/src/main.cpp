#include <iostream>
#include <random>
#include <ctime>

int main(int argc, char* argv[]) {

  int max_num = (argc > 1 ? std::stoi(argv[1]) : 50);

  std::srand(std::time(0));

  std::cout << "===================================================\n"
            << "Welcome to the Hot-Cold Guess game, copyright 2020.\n"
            << "---------------------------------------------------\n\n"
            << "These are the game rules:\n"
            << "    * I’ll choose a random number in [1," << max_num << "]. Your job is to guess that number.\n"
            << "    * From the second guess onward, I’ll tell you if your guess\n"
            << "      is hot (closer than the previous guess) or cold (farther from\n"
            << "      the previous guess).\n"
            << "    * If you wish to quit the game, just type in a negative number.\n\n"
            << "Good luck!\n"
            << "----------------------------------------------------\n\n";
            
  int target = (std::rand() % max_num) + 1;
  
  // std::cout << target << '\n';
  
  int guess{};
  int prev{};
  std::cout << ">>> Guess the number: ";
  std::cin >> guess;
  
  unsigned int tries = 1;
  while (guess != target) {
  
    if (guess < 0) {
      return 0;
    }
  
    std::cout << ">>> Nop, ";
    if (prev == 0) {} 
    else if (abs(target - prev) == abs(target - guess)) {
      std::cout << "it's the same, ";
    } else if (abs(target - prev) > abs(target - guess)) {
      std::cout << "it’s hot though, ";
    } else {
      std::cout << "it’s getting cold, ";
    }
    prev = guess;
    std::cout << "try again: ";
    std::cin >> guess;
    
    ++tries;
  }
  
  std::cout << ">>> Yeah, correct guess!\n\n"
            << "You got it in \'" << tries << "\' tries!\n"
            << "Thanks for playing.\n";

  return 0;
}
