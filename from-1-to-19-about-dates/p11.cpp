#include <iostream>
#include <string>
using namespace std;

struct stDate
{
  short year, month, day;
};

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

stDate dateByDayOrder(short dayOrder, short year)
{

  stDate neededDate;
  neededDate.year = year;
  neededDate.month = 1;
  neededDate.day = dayOrder;

  while (neededDate.day > numberOfDaysInMonth(year, neededDate.month))
  {
    neededDate.day -= numberOfDaysInMonth(year, neededDate.month++);
  }

    return neededDate;
}

void printDate(stDate date)
{
  cout << date.day << "/" << date.month << "/" << date.year;
}

int main()
{

  printDate(dateByDayOrder(numberOfDaysFromYear(2000, 9, 23), 2000));
  return 0;
}
