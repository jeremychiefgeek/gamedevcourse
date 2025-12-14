// Write a program that asks for the name and age of two people, then prints
// which person is older.
//
// Here is the sample output from one run of the program:
//
// Enter the name of person #1: John Bacon
// Enter the age of John Bacon: 37
// Enter the name of person #2: David Jenkins
// Enter the age of David Jenkins: 44
// David Jenkins (age 44) is older than John Bacon (age 37).

#include <iostream>
#include <string>
#include <string_view>

std::string getPersonName(int num)
{
  std::cout << "Enter the name of the person #" << num << ": ";
  std::string input{};
  std::getline(std::cin >> std::ws, input);
  return input;
}

int getPersonsAge(std::string_view sv)
{
  int input{};
  std::cout << "Enter the age of " << sv << ": ";
  std::cin >> input;

  return input;
}

bool isPersonOneOlder(int personOneAge, int personTwoAge)
{
  return personOneAge > personTwoAge;
}

void printResult(std::string_view personOneName, int personOneAge,
                 std::string_view personTwoName, int personTwoAge)
{
  if(isPersonOneOlder(personOneAge, personTwoAge))
    std::cout << personOneName << " (age " << personOneAge
              << ") is older than " << personTwoName << " (age "
              << personTwoAge << ").\n";
  else
    std::cout << personTwoName << " (age " << personTwoAge
              << ") is older than " << personOneName << " (age "
              << personOneAge << ").\n";
}

int main()
{
  const std::string personOneName{getPersonName(1)};
  const int personOneAge{getPersonsAge(personOneName)};

  const std::string personTwoName{getPersonName(2)};
  const int personTwoAge{getPersonsAge(personTwoName)};

  printResult(personOneName, personOneAge, personTwoName, personTwoAge);

  return 0;
}
