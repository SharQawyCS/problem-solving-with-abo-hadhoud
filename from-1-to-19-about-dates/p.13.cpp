#include <iostream>
#include <string>
using namespace std;

struct stDate
{
  short year, month, day;
};

bool isDate1BeforeDate2(stDate date_1, stDate date_2)
{
  return (date_1.year < date_2.year) || ((date_1.year == date_2.year) && (date_1.month < date_2.month)) || ((date_1.year == date_2.year) && (date_1.month == date_2.month) && (date_1.day < date_2.day));
}

void printDate(stDate date)
{
  cout << date.day << "/" << date.month << "/" << date.year;
}

int main()
{
  stDate date1, date2;
  date1.year = 3200, date1.month = 11, date1.day = 9;
  date2.year = 2022, date2.month = 11, date2.day = 10;

  cout << isDate1BeforeDate2(date1, date2);

  return 0;
}