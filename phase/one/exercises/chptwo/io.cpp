#include "io.h"
#include <iostream>

int readNumber()
{
  int input{};
  std::cout << "Please enter a number: ";
  std::cin >> input;
  return input;
}

void writeAnswer(int answer)
{
  std::cout << "The sum is: " << answer << "\n";
}
