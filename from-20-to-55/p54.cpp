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
int weekdayOfDate(stDate date)
{
  short a = (14 - date.month) / 12;
  short y = date.year - a;
  short m = date.month + 12 * a - 2;
  // Zero is Sunday
  return (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
bool isWeekend(stDate date)
{
  return weekdayOfDate(date) == 6 || weekdayOfDate(date) == 5;
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

bool isDate1BeforeDate2(stDate date_1, stDate date_2)
{
  return (date_1.year < date_2.year) || ((date_1.year == date_2.year) && (date_1.month < date_2.month)) || ((date_1.year == date_2.year) && (date_1.month == date_2.month) && (date_1.day < date_2.day));
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
short diffBetweenTwoDatesSeconedIsBigger(stDate date_1, stDate date_2, bool isLastDayIncluded = false)
{
  short days = 0;
  while (isDate1BeforeDate2(date_1, date_2))
  {
    days++;
    date_1 = increaseDateByOneDay(date_1);
  }
  return (days + isLastDayIncluded);
}

//
short calcActualVacation(stDate date_1, stDate date_2)
{
  short vacationDays = 0;
  while (isDate1BeforeDate2(date_1, date_2))
  {
    if (!isWeekend(date_1))
    {
      vacationDays++;
    }
    date_1 = increaseDateByOneDay(date_1);
  }
  return vacationDays;
}

int main()
{
  stDate date1, date2;
  date1.year = 2022, date1.month = 1, date1.day = 1;
  date2.year = 2022, date2.month = 2, date2.day = 2;

  cout << calcActualVacation(date1, date2);

  return 0;
}