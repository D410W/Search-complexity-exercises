#include <iostream>
#include <random>
#include <ctime>

void make_guess(int &old_guess, int new_guess) {
  old_guess = new_guess;
  std::cout << new_guess << '\n';
}

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
            
  int target = (argc > 2 ? std::stoi(argv[1]) : (std::rand() % max_num) + 1);
  
  std::cout << target << '\n';
  
  int guess{};
  int prev{};
  std::cout << ">>> Guess the number: ";
  
  // std::cin >> guess;
  make_guess(guess, max_num/2);
  
  int limit_min = 1;
  int limit_max = max_num;
  short int temp = 0;
  bool mid_guess = false;
  
  unsigned int tries = 1;
  while (guess != target && tries < 20) {
    
    std::cout << ">>> Nop, ";
    
    if (prev == 0) {} 
    else if (abs(target - prev) == abs(target - guess)) {
      std::cout << "it's the same, ";
      if (mid_guess) temp = 0;
    } else if (abs(target - prev) > abs(target - guess)) {
      std::cout << "it’s hot though, ";
      if (mid_guess) temp = 1;
    } else {
      std::cout << "it’s getting cold, ";
      if (mid_guess) temp = -1;
    }
    std::cout << "try again: ";
  
    if (mid_guess) {
      if (temp == 0) {
        int mid = (prev + guess)/2;
        limit_min = mid;
        limit_max = mid;
      } else if (temp == 1) {
        limit_min = prev;
      } else if (temp == -1) {
        limit_max = guess - 1;
      }
    }
    
    std::cout << '\n' << limit_min << ' ' << limit_max << ' ' << prev << ' ' << guess << ' ' << mid_guess << '\n';
    
    int tomake_guess{};
    if (mid_guess) {
      tomake_guess = (limit_max + limit_min)/2;
    } else {
      tomake_guess = (limit_max + limit_min)/2 + (limit_max - limit_min)/4;
      if (tomake_guess == guess) tomake_guess++;
    }
    
    prev = guess;
    make_guess(guess, tomake_guess);
    
    mid_guess = !mid_guess;
    ++tries;
  }
  
  std::cout << ">>> Yeah, correct guess!\n\n"
            << "You got it in \'" << tries << "\' tries!\n"
            << "Thanks for playing.\n";

  return 0;
}
