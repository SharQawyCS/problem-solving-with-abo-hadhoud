#include <iostream>
#include <string>
using namespace std;

struct stDate
{
  short year, month, day;
};

// short diffBetweenTwoDates(stDate date_1, stDate date_2)
// {
//   if (isDate1EqualDate2(date_1, date_2))
//   {
//     return 0;
//   }

//   short diff = numberOfDaysFromYear(date_1.year, date_1.month, date_1.day) - numberOfDaysFromYear(date_2.year, date_2.month, date_2.day);

//   short yearsDiff = 0;
//   for (int i = date_2.year; i < date_1.year; ++i)
//   {
//     yearsDiff += numberOfDaysInYear(i);
//   }

//   diff += yearsDiff;

//   return diff;
// }
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

void swapTwoDates(stDate &date_1, stDate &date_2)
{
  stDate temp = date_1;
  date_1 = date_2;
  date_2 = temp;
}

short diffBetweenTwoDates(stDate date_1, stDate date_2, bool isLastDayIncluded = false)
{
  short flag = 1;
  if (!isDate1BeforeDate2(date_1, date_2))
  {
    swapTwoDates(date_1, date_2);
    flag = -1;
  }

  short days = 0;
  while (isDate1BeforeDate2(date_1, date_2))
  {
    days++;
    date_1 = increaseDateByOneDay(date_1);
  }
  return flag * (days + isLastDayIncluded);
}

int main()
{
  stDate date1, date2;
  date2.year = 1950, date1.month = 1, date1.day = 1;
  date1.year = 2022, date2.month = 1, date2.day = 1;

  cout << diffBetweenTwoDates(date1, date2, 1);
  return 0;
}
