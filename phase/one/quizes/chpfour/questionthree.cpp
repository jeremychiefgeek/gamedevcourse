// Extra credit: This one is a little more challenging.
//
// Write a short program to simulate a ball being dropped off of a tower. To
// start, the user should be asked for the height of the tower in meters.
// Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity
// (the ball is not moving to start). Have the program output the height of the
// ball above the ground after 0, 1, 2, 3, 4, and 5 seconds. The ball should
// not go underneath the ground (height 0).
//
// Use a function to calculate the height of the ball after x seconds. The
// function can calculate how far the ball has fallen after x seconds using the
// following formula: distance fallen = gravity_constant * x_seconds2 / 2

#include <iostream>

const double GRAVITY = 9.8;

double getHeight()
{
  std::cout << "Please enter the height of the tower: ";
  double input{};
  std::cin >> input;
  return input;
}

double calculateBallHeight(double height, int seconds)
{
  double fallDistance{GRAVITY * (seconds * seconds) / 2.0};
  double towerHeight{height - fallDistance};

  if(towerHeight < 0.0)
    return 0.0;

  return towerHeight;
}

void printResult(double height, int seconds)
{
  double result = calculateBallHeight(height, seconds);

  if(result <= 0.0)
    std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
  else
    std::cout << "At " << seconds
              << " seconds, the ball is at height: " << result << " meters\n";
}

int main()
{
  double height = getHeight();
  printResult(height, 0);
  printResult(height, 1);
  printResult(height, 2);
  printResult(height, 3);
  printResult(height, 4);
  printResult(height, 5);

  return 0;
}
