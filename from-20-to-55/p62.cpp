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

bool isValidDate(stDate date)
{
  return (date.year > 0) && (date.month <= 12 && date.month >= 1) && (date.day <= numberOfDaysInMonth(date.year, date.month));
}

int main()
{
  stDate date1, date2;
  date1.year = 2000, date1.month = 15, date1.day = 25;
  date2.year = 2022, date2.month = 2, date2.day = 2;

  cout << isValidDate(date1);

  return 0;
}