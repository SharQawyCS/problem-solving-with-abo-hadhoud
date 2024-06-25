#include <iostream>
#include <string>
using namespace std;

bool isLeapYear(short year)
{
  return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int main()
{
  cout << isLeapYear(1900);
  return 0;
}