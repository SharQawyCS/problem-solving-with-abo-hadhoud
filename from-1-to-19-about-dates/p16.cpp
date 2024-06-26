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

stDate increaseDateByOneDay(stDate date)
{
  if (isLastDayInMonth(date))
  {
    date.day = 1;

    if (isLastMonthInYear(date.month))
    {
      date.month = 1;
      date.year++;
    }
    else
    {
      date.month++;
    }
  }
  else
  {
    date.day++;
  }

  return date;
}

void printDate(stDate date)
{
  cout << date.day << "/" << date.month << "/" << date.year;
}

int main()
{
  stDate myDate;
  myDate.year = 2024, myDate.month = 12, myDate.day = 31;
  printDate(increaseDateByOneDay(myDate));
  return 0;
}
