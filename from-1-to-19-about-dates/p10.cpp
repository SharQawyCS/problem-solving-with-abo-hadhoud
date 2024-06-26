#include <iostream>
#include <string>
using namespace std;

bool isLeapYear(short year)
{
  return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

short numberOfDaysInMonth(short year, short month)
{
  if (month > 12 || month < 1)
  {
    return 0;
  }
  short days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return (month == 2) ? isLeapYear(year) ? 29 : 28 : days[month - 1];
}

short numberOfDaysFromYear(short year, short month, short day)
{
  // For Validation
  if (day <= 0 || day > numberOfDaysInMonth(year, month))
  {
    return 0;
  }

  short days = day;
  for (int i = 1; i < month; ++i)
  {
    days += numberOfDaysInMonth(year, i);
  }
  return days;
}

int main()
{
  cout << numberOfDaysFromYear(2022, 4, 20);
  return 0;
}
