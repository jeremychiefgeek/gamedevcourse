// 1. Write a function called doubleNumber() that takes one integer parameter.
// The function should return double the value of the parameter.
// 2. Write a complete program that reads an integer from the user, doubles it
// using the doubleNumber() function you wrote in the previous quiz question,
// and then prints the doubled value out to the console.
#include <iostream>

int doubleNumber(int num)
{
  return num * 2;
}

int getIntFromUsr()
{
  int input{};
  std::cout << "Enter a number: ";
  std::cin >> input;
  return input;
}

int main()
{
  int num = getIntFromUsr();

  std::cout << "Double that is: " << doubleNumber(num) << ".\n";

  return 0;
}
