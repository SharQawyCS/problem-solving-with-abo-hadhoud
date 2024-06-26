
#include <iostream>
#include <string>
using namespace std;

struct stDate
{
  short year, month, day;
};

// Needed
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
short numberOfDaysInYear(short year)
{
  return isLeapYear(year) ? 366 : 365;
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

// 1
int weekdayOfDate(stDate date)
{
  short a = (14 - date.month) / 12;
  short y = date.year - a;
  short m = date.month + 12 * a - 2;
  // Zero is Sunday
  return (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
// 2
bool isEndOfWeek(stDate date)
{
  return weekdayOfDate(date) == 6;
}
// 3
bool isWeekend(stDate date)
{
  return weekdayOfDate(date) == 6 || weekdayOfDate(date) == 5;
}
// 4
bool isBusinessDay(stDate date)
{
  return !isWeekend(date);
}
// 5
short daysUntilEndOfWeek(stDate date)
{
  return 6 - weekdayOfDate(date);
}
// 6
short daysUntilEndOfMonth(stDate date)
{
  return numberOfDaysInMonth(date.year, date.month) - date.day;
}
// 7
short daysUntilEndOfYear(stDate date)
{
  return numberOfDaysInYear(date.year) - numberOfDaysFromYear(date.year, date.month, date.day);
}

int main()
{
  stDate date1, date2;
  date1.year = 2022, date1.month = 11, date1.day = 29;
  date2.year = 2022, date2.month = 11, date2.day = 10;

  cout << weekdayOfDate(date1) << "\n";
  cout << isEndOfWeek(date1) << "\n";
  cout << isWeekend(date1) << "\n";
  cout << isBusinessDay(date1) << "\n";
  cout << daysUntilEndOfWeek(date1) << "\n";
  cout << daysUntilEndOfMonth(date1) << "\n";
  cout << daysUntilEndOfYear(date1) << "\n";

  return 0;
}