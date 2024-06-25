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

// // // ///