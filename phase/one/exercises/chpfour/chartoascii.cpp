#include <iostream>

void printCharAsInt(int c)
{
  std::cout << c << "\n";
}
int main()
{
  char input{};
  std::cout << "Enter a single character: ";
  std::cin >> input;
  std::cout << "You entered '" << input << "', which has ASCII code ";
  printCharAsInt(input);
  return 0;
}

// int main()
// {
//   char input{};
//   std::cout << "Enter a single character: ";
//   std::cin >> input;
//   std::cout << "You entered '" << input << "', which has ASCII code "
//             << static_cast<int>(input) << "\n";
//   return 0;
// }
