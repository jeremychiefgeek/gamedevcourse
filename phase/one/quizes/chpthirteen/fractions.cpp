#include <iostream>

struct Fraction
{
  int numerator{0};
  int denominator{1};
};

Fraction getFractionFromUser()
{
  std::cout << "Enter a value for the numerator: ";
  Fraction input{};
  std::cin >> input.numerator;
  std::cout << "Enter a value for the denominator: ";
  std::cin >> input.denominator;

  return input;
};

auto multiplyFraction(const Fraction &fractionOne, const Fraction &fractionTwo)
  -> Fraction
{
  return Fraction{(fractionOne.numerator * fractionTwo.numerator),
                  (fractionOne.denominator * fractionTwo.denominator)};
}

void printAndMultiplyFranction(const Fraction &fractionOne,
                               const Fraction &fractionTwo)
{
  auto result = multiplyFraction(fractionOne, fractionTwo);

  std::cout << "Your fractions multiplied together: " << result.numerator
            << "/" << result.denominator << "\n";
}

int main()
{
  Fraction fractionOne{getFractionFromUser()};
  Fraction fractionTwo{getFractionFromUser()};
  printAndMultiplyFranction(fractionOne, fractionTwo);

  return 0;
}
