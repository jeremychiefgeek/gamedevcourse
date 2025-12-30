#include <iostream>

void fizzbuzz(int countTo);
void fizzbuzzpop(int countTo);

int main()
{
  fizzbuzz(15);
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "Fizz Buzz Pop\n";
  fizzbuzzpop(150);

  return 0;
}

void fizzbuzz(int countTo)
{
  for(int i{1}; i <= countTo; ++i)
  {
    if(i % 3 == 0 && i % 5 == 0)
      std::cout << "fizzbuzz" << "\n";
    else if(i % 3 == 0)
      std::cout << "fizz" << "\n";
    else if(i % 5 == 0)
      std::cout << "buzz" << "\n";
    else
      std::cout << i << "\n";
  }
}

void fizzbuzzpop(int countTo)
{
  for(int i{1}; i <= countTo; ++i)
  {
    if(i % 3 == 0)
      std::cout << "fizz";
    if(i % 5 == 0)
      std::cout << "buzz";
    if(i % 7 == 0)
      std::cout << "pop";
    if(i % 3 != 0 && i % 5 != 0 && i % 7 != 0)
      std::cout << i;

    std::cout << "\n";
  }
}
