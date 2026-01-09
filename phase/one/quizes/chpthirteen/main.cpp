#include <iostream>

struct AddRevenue
{
  int adsWatched{0};
  double percentClicked{0.0};
  double earnings{0.0};
};

void printAddRevenue(const AddRevenue &revenue)
{
  std::cout << "Ads Watched: " << revenue.adsWatched
            << "\nPercentage Clicked: " << revenue.percentClicked
            << "\nEarnings per click: " << revenue.earnings << "\n";

  std::cout << "Total Earnings: "
            << (revenue.adsWatched * revenue.percentClicked * revenue.earnings)
            << "\n";
}

int main()
{
  printAddRevenue({1000, 0.14, .003});
  std::cout << '\n';
  printAddRevenue({100, 0.2, 1.003});
  return 0;
}
