#include <iostream>
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

int main()
{
  cout << convertNumToString(94969090806);
  return 0;
}