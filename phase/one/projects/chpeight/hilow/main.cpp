#include <iostream>
#include "Random.h"

int getUserGuess(int x)
{
  std::cout << "Guess #" << x << ": ";
  int input{0};
  std::cin >> input;
  return input;
}

bool isGuessCorrect(int guess, int answer)
{
  if(guess == answer)
  {
    std::cout << "Correct! You win!\n";
    return true;
  }
  if(guess > answer)
    std::cout << "Your guess is too high.\n";
  else
    std::cout << "Your guess is too low.\n";

  return false;
}

int main()
{
  bool isPlaying{true};
  while(isPlaying)
  {
    int answer{Random::get(1, 100)};
    std::cout << "Let's play a game. I'm thinking of a number between 1 and "
                 "100. You have 7 tries to guess what it is.\n";
    int userTry{1};
    while(userTry <= 7)
    {
      int guess{getUserGuess(userTry)};
      if(isGuessCorrect(guess, answer))
        break;
      ++userTry;
    }

    if(userTry > 7)
      std::cout << "Sorry, you lose. The correct number was " << answer
                << ".\n";

    std::cout << "Would you like to play again (y/n)? ";
    char playerCheck{};
    std::cin >> playerCheck;

    if(playerCheck == 'n')
      break;
  }

  std::cout << "Thanks you for playing.\n";

  return 0;
}
