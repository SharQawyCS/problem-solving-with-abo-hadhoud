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

stDate getDateAfterDays(stDate date, short days)
{
  short remainingDays = days;

  while (remainingDays > numberOfDaysInMonth(date.year, date.month) - date.day)
  {
    remainingDays = remainingDays - numberOfDaysInMonth(date.year, date.month) + date.day;
    date.month == 12 ? date.month = 1 : date.month++;
    date.month == 1 ? date.year++ : date.year;
    date.day = 0;
  }

  date.day = remainingDays + date.day;
  return date;
}

void printDate(stDate date)
{
  cout << date.day << "/" << date.month << "/" << date.year;
}

int main()
{
  stDate myDate;
  myDate.year = 2022, myDate.month = 11, myDate.day = 10;
  printDate(getDateAfterDays(myDate, 1000));
  return 0;
}
