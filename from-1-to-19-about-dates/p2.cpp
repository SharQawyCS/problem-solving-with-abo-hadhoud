#include <iostream>
#include <string>
using namespace std;

bool isLeapYear(short year)
{
  if (year % 100 == 0)
  {
    if (year % 400 == 0)
    {
      return true;
    }
    return 0;
  }
  if (year % 4 == 0)
  {
    return true;
  }
  return false;
}

int main()
{
  cout << isLeapYear(1900);
  return 0;
}