#include <iostream>
#include <string>

std::string getName()
{
  std::cout << "Please enter your name: ";
  std::string input{};
  std::getline(std::cin >> std::ws, input);
  return input;
}

int getAge()
{
  std::cout << "Please enter your age: ";
  int age{};
  std::cin >> age;
  return age;
}

void calculateAgeAndNameLengthAndPrint(int age, int nameLength)
{
  int sum = age + nameLength;
  std::cout << "Your age + name length is " << sum << "\n";
}

int main()
{
  std::string name{};
  name = getName();
  int age{};
  age = getAge();
  calculateAgeAndNameLengthAndPrint(age, static_cast<int>(name.length()));
  return 0;
}
