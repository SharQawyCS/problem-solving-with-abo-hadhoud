#include <iostream>
#include <string>
using namespace std;

struct stDate
{
  short year, month, day;
};
int weekdayOfDate(stDate date)
{
  short a = (14 - date.month) / 12;
  short y = date.year - a;
  short m = date.month + 12 * a - 2;
  // Zero is Sunday
  return (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

int main()
{
  cout << weekdayOfDate({.year = 2005, .month = 8, .day = 19});
  return 0;
}
