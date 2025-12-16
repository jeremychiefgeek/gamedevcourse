#include <iostream>

constexpr bool isEven(int num)
{
  return (num % 2) == 0;
}

int getNumber()
{
  std::cout << "Please enter a number: ";
  int input{};
  std::cin >> input;
  return input;
}

int main()
{
  int inputNum{getNumber()};

  if(isEven(inputNum))
    std::cout << inputNum << " is even.\n";
  else
    std::cout << inputNum << " is odd.\n";

  return 0;
}
