#include <iostream>
#include <string>
using namespace std;

bool isLeapYear(short year)
{
  return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

short numberOfDaysInYear(short year)
{
  return isLeapYear(year) ? 366 : 365;
}
short numberOfHoursInYear(short year)
{
  return numberOfDaysInYear(year) * 24;
}
int numberOfMinutesInYear(short year)
{
  return numberOfHoursInYear(year) * 60;
}
int numberOfSecondsInYear(short year)
{
  return numberOfMinutesInYear(year) * 60;
}

void printYearDetails(short year)
{
  cout << "Number of Days    in year [" << year << "] is:" << numberOfDaysInYear(year) << "\n";
  cout << "Number of Hours   in year [" << year << "] is:" << numberOfHoursInYear(year) << "\n";
  cout << "Number of Minutes in year [" << year << "] is:" << numberOfMinutesInYear(year) << "\n";
  cout << "Number of Seconds in year [" << year << "] is:" << numberOfSecondsInYear(year) << endl;
}

int main()
{
  printYearDetails(1971);
  return 0;
}