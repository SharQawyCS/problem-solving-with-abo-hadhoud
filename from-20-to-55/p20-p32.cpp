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
// 1
stDate increaseDateByXDays(stDate date, short days)
{
  for (short i = 0; i < days; ++i)
  {
    increaseDateByOneDay(date);
  }
  return date;
}
// 2
stDate increaseDateByOneWeek(stDate date)
{
  for (short i = 0; i < 7; ++i)
  {
    increaseDateByOneDay(date);
  }
  return date;
}
// 3
stDate increaseDateByXWeeks(stDate date, short weeks)
{
  for (short i = 0; i < weeks; ++i)
  {
    increaseDateByOneWeek(date);
  }
  return date;
}
// 4
stDate increaseDateByOneMonth(stDate date)
{
  if (date.month == 12)
  {
    date.month = 1;
    date.year++;
  }
  else
  {
    date.month++;
  }
  if (date.day > numberOfDaysInMonth(date.year, date.month))
  {
    date.day = numberOfDaysInMonth(date.year, date.month);
  }
  return date;
}
// 5
stDate increaseDateByXMonths(stDate date, short months)
{
  for (short i = 0; i < months; ++i)
  {
    increaseDateByOneMonth(date);
  }
  return date;
}
// 6
stDate increaseDateByOneYear(stDate date)
{
  date.year++;
  return date;
}
// 7
stDate increaseDateByXYears(stDate date, short years)
{
  for (short i = 0; i < years; ++i)
  {
    increaseDateByOneYear(date);
  }
  return date;
}
// 8
stDate increaseDateByXYearsFaster(stDate date, short years)
{
  date.year += years;
  return date;
}
// 9
stDate increaseDateByOneDecade(stDate date)
{
  date.year += 10;
  return date;
}
// 10
stDate increaseDateByXDecades(stDate date, short decades)
{
  for (short i = 0; i < decades; ++i)
  {
    increaseDateByOneDecade(date);
  }
  return date;
}
// 11
stDate increaseDateByXYearsFaster(stDate date, short decades)
{
  date.year += decades * 10;
  return date;
}
// 12
stDate increaseDateByOneCentury(stDate date)
{
  date.year += 100;
  return date;
}
// 13
stDate increaseDateByOneMillennim(stDate date)
{
  date.year += 1000;
  return date;
}

int main()
{
  stDate date1, date2;
  date1.year = 2022, date1.month = 11, date1.day = 10;
  date2.year = 2022, date2.month = 11, date2.day = 10;

  return 0;
}