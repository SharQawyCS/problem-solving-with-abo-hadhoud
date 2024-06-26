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

int weekdayOfDate(short year, short month, short day)
{
  short a = (14 - month) / 12;
  short y = year - a;
  short m = month + 12 * a - 2;
  // Zero is Sunday
  return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
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

void printMonthCalendar(short year, short month)
{
  short monthDays = numberOfDaysInMonth(year, month);
  short firstWeekday = weekdayOfDate(year, month, 1);
  string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  cout << "_______________" << months[month - 1] << "_______________\n\n";

  cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

  for (int i = 0; i < firstWeekday; ++i)
  {
    cout << "     "; // 5 spaces
  }

  for (int i = 1; i <= monthDays; ++i)
  {
    if (i < 10)
    {
      cout << " ";
    }
    cout << " " << i << "  ";
    if (i % 7 == (7 - firstWeekday) % 7)
    {
      cout << "\n";
    }
  }

  cout << "\n_________________________________\n"
       << endl;
}

void printYearCalendar(short year)
{
  cout << "\n_________________________________\n";
  cout << "\n          " << year << " Calendar";
  cout << "\n_________________________________\n\n";

  for (int i = 0; i < 12; ++i)
  {
    printMonthCalendar(year, i + 1);
    cout << "\n";
  }
}

int main()
{
  printYearCalendar(2022);
  return 0;
}
