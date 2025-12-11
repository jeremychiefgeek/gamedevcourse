#include <iostream>

double enterDouble()
{
  double input{};
  std::cout << "Enter a double value: ";
  std::cin >> input;
  return input;
}
char enterMathSymbol()
{
  char input{};
  std::cout << "Enter +, -, *, or /: ";
  std::cin >> input;
  return input;
}

void doMathAndPrint(double a, double b, char mathSym)
{
  double result{};
  if(mathSym == '+')
    result = a + b;
  else if(mathSym == '-')
    result = a - b;
  else if(mathSym == '*')
    result = a * b;
  else if(mathSym == '/')
    result = a / b;
  else
    return;

  std::cout << a << " " << mathSym << " " << b << " is " << result << "\n";
}

int main()
{
  // Get First double
  double a = enterDouble();
  // Get Second Double
  double b = enterDouble();
  // Get math symbol
  char mathSym = enterMathSymbol();

  doMathAndPrint(a, b, mathSym);

  return 0;
}
