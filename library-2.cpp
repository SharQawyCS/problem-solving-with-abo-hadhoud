#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string convertNumToString(long num)
{
  if (num == 0)
  {
    return "";
  }
  if (num >= 1 && num <= 19)
  {
    string arr[] =
        {"", "one", "two", "three", "four", "five", "six", "seven",
         "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
         "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    return arr[num];
  }
  if (num >= 20 && num <= 99)
  {
    string arr[] = {"", "", "twenty", "thirty", "forty", "fifty",
                    "sixty", "seventy", "eighty", "ninety"};
    return (arr[num / 10] + " " + convertNumToString(num % 10));
  }
  if (num >= 100 && num <= 199)
  {
    return ("one hundred " + convertNumToString(num % 100));
  }
  if (num >= 200 && num <= 999)
  {
    return (convertNumToString(num / 100) + " hundreds " + convertNumToString(num % 100));
  }
  if (num >= 1000 && num <= 1999)
  {
    return ("one thousand " + convertNumToString(num % 1000));
  }
  if (num >= 2000 && num <= 999999)
  {
    return (convertNumToString(num / 1000) + " thousands " + convertNumToString(num % 1000));
  }

  if (num >= 1000000 && num <= 1999999)
  {
    return "one million " + convertNumToString(num % 1000000);
  }
  if (num >= 2000000 && num <= 999999999)
  {
    return (convertNumToString(num / 1000000) + " millions " + convertNumToString(num % 1000000));
  }
  if (num >= 1000000000 && num <= 1999999999)
  {
    return "One Billion " + convertNumToString(num % 1000000000);
  }
  else
  {
    return convertNumToString(num / 1000000000) + " Billions " + convertNumToString(num % 1000000000);
  }
}

bool isLeapYear(short year)
{
  if (year % 100 == 0)
  {
    if (year % 400 == 0)
    {
      return true;
    }
    return false;
  }
  if (year % 4 == 0)
  {
    return true;
  }
  return false;
}

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

struct stDate
{
  short year, month, day;
};
int weekdayOfDate(stDate date)
{
  short a = (14 - date.month) / 12;
  short y = date.year - a;
  short m = date.month + 12 * a - 2;
  // Zero is Sunday
  return (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
int weekdayOfDate(short year, short month, short day)
{
  short a = (14 - month) / 12;
  short y = year - a;
  short m = month + 12 * a - 2;
  // Zero is Sunday
  return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
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
stDate dateByDayOrder(short dayOrder, short year)
{
  stDate neededDate;
  neededDate.year = year;
  neededDate.month = 1;
  neededDate.day = dayOrder;

  while (neededDate.day > numberOfDaysInMonth(year, neededDate.month))
  {
    neededDate.day -= numberOfDaysInMonth(year, neededDate.month++);
  }

  return neededDate;
}

void printDate(stDate date)
{
  cout << date.day << "/" << date.month << "/" << date.year;
}

bool isDate1BeforeDate2(stDate date_1, stDate date_2)
{
  return (date_1.year < date_2.year) || ((date_1.year == date_2.year) && (date_1.month < date_2.month)) || ((date_1.year == date_2.year) && (date_1.month == date_2.month) && (date_1.day < date_2.day));
}
bool isDate1EqualDate2(stDate date_1, stDate date_2)
{
  return (date_1.year == date_2.year) && (date_1.month == date_2.month) && (date_1.day == date_2.day);
}

bool isLastDayInMonth(stDate date)
{
  return date.day == numberOfDaysInMonth(date.year, date.month);
}
bool isLastMonthInYear(short month)
{
  return month == 12;
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

stDate getCurrentDate()
{
  time_t t = time(nullptr);
  tm *now = localtime(&t);

  stDate currentDate;
  currentDate.day = now->tm_mday;
  currentDate.month = now->tm_mon + 1;    // tm_mon is 0-11, so we add 1
  currentDate.year = now->tm_year + 1900; // tm_year is years since 1900

  return currentDate;
}

short yourAgeInDaye(stDate BirthDate)
{
  return diffBetweenTwoDates(BirthDate, getCurrentDate());
}

// // // ///