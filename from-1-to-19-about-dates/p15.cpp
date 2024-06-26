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

bool isLastDayInMonth(stDate date)
{
  return date.day == numberOfDaysInMonth(date.year, date.month);
}

bool isLastMonthInYear(short month)
{
  return month == 12;
}

void printDate(stDate date)
{
  cout << date.day << "/" << date.month << "/" << date.year;
}

int main()
{
  stDate date1, date2;
  date1.year = 2024, date1.month = 2, date1.day = 29;
  date2.year = 2022, date2.month = 11, date2.day = 10;

  cout << isLastDayInMonth(date1);

  return 0;
}