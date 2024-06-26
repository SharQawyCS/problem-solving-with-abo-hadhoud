#include <iostream>
#include <string>
using namespace std;

struct stDate
{
  short year, month, day;
};

// Needed
short numberOfDaysInMonth(short year, short month)
{
  if (month > 12 || month < 1)
  {
    return 0;
  }
  short days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return (month == 2) ? isLeapYear(year) ? 29 : 28 : days[month - 1];
}
bool isLeapYear(short year)
{
  return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}
bool isLastDayInMonth(stDate date)
{
  return date.day == numberOfDaysInMonth(date.year, date.month);
}
bool isLastMonthInYear(short month)
{
  return month == 12;
}

// Declared
stDate decreaseDateByOneDay(stDate date)
{
  if (date.day == 1)
  {
    if (date.month == 1)
    {
      date.year--;
      date.month == 12;
      date.day = 31;
    }
    else
    {
      date.month--;
      date.day = numberOfDaysInMonth(date.year, date.month);
    }
  }
  else
  {
    date.day--;
  }

  return date;
}
// 1
stDate decreaseDateByXDays(stDate date, short days)
{
  for (short i = 0; i < days; ++i)
  {
    decreaseDateByOneDay(date);
  }
  return date;
}
// 2
stDate decreaseDateByOneWeek(stDate date)
{
  for (short i = 0; i < 7; ++i)
  {
    decreaseDateByOneDay(date);
  }
  return date;
}
// 3
stDate decreaseDateByXWeeks(stDate date, short weeks)
{
  for (short i = 0; i < weeks; ++i)
  {
    decreaseDateByOneWeek(date);
  }
  return date;
}
// 4
stDate decreaseDateByOneMonth(stDate date)
{
  if (date.month == 1)
  {
    date.month = 12;
    date.year--;
  }
  else
  {
    date.month--;
  }
  if (date.day > numberOfDaysInMonth(date.year, date.month))
  {
    date.day = numberOfDaysInMonth(date.year, date.month);
  }
  return date;
}
// 5
stDate decreaseDateByXMonths(stDate date, short months)
{
  for (short i = 0; i < months; ++i)
  {
    decreaseDateByOneMonth(date);
  }
  return date;
}
// 6
stDate decreaseDateByOneYear(stDate date)
{
  date.year--;
  return date;
}
// 7
stDate decreaseDateByXYears(stDate date, short years)
{
  for (short i = 0; i < years; ++i)
  {
    decreaseDateByOneYear(date);
  }
  return date;
}
// 8
stDate decreaseDateByXYearsFaster(stDate date, short years)
{
  date.year -= years;
  return date;
}
// 9
stDate decreaseDateByOneDecade(stDate date)
{
  date.year -= 10;
  return date;
}
// 10
stDate decreaseDateByXDecades(stDate date, short decades)
{
  for (short i = 0; i < decades; ++i)
  {
    decreaseDateByOneDecade(date);
  }
  return date;
}
// 11
stDate decreaseDateByXYearsFaster(stDate date, short decades)
{
  date.year -= decades * 10;
  return date;
}
// 12
stDate decreaseDateByOneCentury(stDate date)
{
  date.year -= 100;
  return date;
}
// 13
stDate decreaseDateByOneMillennim(stDate date)
{
  date.year -= 1000;
  return date;
}

int main()
{
  stDate date1, date2;
  date1.year = 2022, date1.month = 11, date1.day = 10;
  date2.year = 2022, date2.month = 11, date2.day = 10;

  return 0;
}