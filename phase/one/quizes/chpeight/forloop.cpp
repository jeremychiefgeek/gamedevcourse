#include <iostream>

void myEvenSolution();
void webEvenSolution();
int sumTo(int value);

int main()
{
  myEvenSolution();
  std::cout << "\n";
  webEvenSolution();
  std::cout << "\n";
  std::cout << "Passing 5 to sumTo.\n";
  int sumToResult{};
  sumToResult = sumTo(5);
  std::cout << "SumTo Result: " << sumToResult << "\n";

  return 0;
}

void myEvenSolution()
{
  for(int i{1}; i <= 20; ++i)
  {
    if((i % 2) == 0)
    {
      std::cout << i << "\n";
    }
  }
}

void webEvenSolution()
{
  for(int i{1}; i <= 20; i += 2)
    std::cout << i << "\n";
}

int sumTo(int value)
{
  int result{0};
  for(int i{1}; i <= value; ++i)
  {
    result += i;
  }

  return result;
}
