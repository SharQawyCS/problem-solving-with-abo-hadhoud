#include <iostream>
#include <string>
using namespace std;

struct stDate
{
  short year, month, day;
};
struct stPeriod
{
  stDate startDate, endDate;
};

bool isDate1BeforeDate2(stDate date_1, stDate date_2)
{
  return (date_1.year < date_2.year) || ((date_1.year == date_2.year) && (date_1.month < date_2.month)) || ((date_1.year == date_2.year) && (date_1.month == date_2.month) && (date_1.day < date_2.day));
}

//

bool isTwoPeriodsOverlab(stPeriod period_1, stPeriod period_2)
{
  return !isDate1BeforeDate2(period_2.endDate, period_1.startDate) && !isDate1BeforeDate2(period_1.endDate, period_2.startDate);
}

int main()
{

  return 0;
}