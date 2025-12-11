#include <iostream>

bool isPrime(int x)
{
  return x == 2 || x == 3 || x == 5 || x == 7;
}

int main()
{
  int input{};
  std::cout << "Enter a number between 0 and 9 (inclusive):";
  std::cin >> input;

  if(input < 0 || input > 9)
    std::cout << "The input was invalid." << "\n";
  else if(isPrime(input))
    std::cout << "The input is prime." << "\n";
  else
    std::cout << "The input is not prime." << "\n";

  return 0;
}
