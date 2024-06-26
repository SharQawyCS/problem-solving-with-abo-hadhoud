#include <iostream>
#include <string>
using namespace std;

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
short numberOfHoursInMonth(short year, short month)
{
  return numberOfDaysInMonth(year, month) * 24;
}
int numberOfMinutesInMonth(short year, short month)
{
  return numberOfHoursInMonth(year, month) * 60;
}
int numberOfSecondsInMonth(short year, short month)
{
  return numberOfMinutesInMonth(year, month) * 60;
}

void prshortYearDetails(short year, short month)
{
  cout << "Number of Days    in year [" << year << "] is:" << numberOfDaysInMonth(year, month) << "\n";
  cout << "Number of Hours   in year [" << year << "] is:" << numberOfHoursInMonth(year, month) << "\n";
  cout << "Number of Minutes in year [" << year << "] is:" << numberOfMinutesInMonth(year, month) << "\n";
  cout << "Number of Seconds in year [" << year << "] is:" << numberOfSecondsInMonth(year, month) << endl;
}

int main()
{
  prshortYearDetails(4245, 2);
  return 0;
}