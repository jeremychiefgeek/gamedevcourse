#include <iostream>

void sort2(int &x, int &y)
{
  // i could have used std::swap but didn't know I was allowed, lol
  if(x > y)
  {
    int temp{x};
    x = y;
    y = temp;
  }
}

int main()
{
  int x{7};
  int y{5};

  std::cout << x << ' ' << y << '\n'; // should print 7 5

  sort2(x, y); // make sure sort works when values need to be swapped
  std::cout << x << ' ' << y << '\n'; // should print 5 7

  sort2(x, y); // make sure sort works when values don't need to be swapped
  std::cout << x << ' ' << y << '\n'; // should print 5 7

  return 0;
}
