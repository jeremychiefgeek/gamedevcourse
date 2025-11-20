#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter 3 number: "; // ask user for a number
    int a{}; // define variable x to hold user input
    int b{};
    int c{};
    std::cin >> a >> b >> c; // get number from keyboard and store it in variable x
    std::cout << "You entered " << a << ", " << b << ", and " << c << ".\n";

    return 0;
}
