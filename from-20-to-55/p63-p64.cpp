#include <iostream>
#include <string>
using namespace std;

struct stDate
{
  short year, month, day;
};

vector<string> splitString(string S1, string Delim)
{
  vector<string> vString;
  short pos = 0;
  string sWord; // define a string variable
                // use find() function to get the position of the delimiters
  while ((pos = S1.find(Delim)) != std::string::npos)
  {
    sWord = S1.substr(0, pos);
    // store the word
    if (sWord != "")
    {
      vString.push_back(sWord);
    }
    S1.erase(0, pos + Delim.length());
    /* erase() until positon and move to next word. */
  }
  if (S1 != "")
  {
    vString.push_back(S1); // it adds last word of the string.
  }
  return vString;
}

stDate stringToDate(string dateString)
{
  vector<string> vString = splitString(dateString, "/");
  stDate date;
  date.day = short(stoi(vString[0]));
  date.month = short(stoi(vString[1]));
  date.year = short(stoi(vString[2]));

  return date;
}

string dateToString(stDate date)
{
  string dateStr = "";
  dateStr += to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
  return dateStr;
}

string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
{
  short pos = S1.find(StringToReplace);
  while (pos != std::string::npos)
  {
    S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
    pos = S1.find(StringToReplace); //
  }
  return S1;
}

string formatDate(stDate date, string format = "dd/mm/yyyy")
{
  string formattedDate = "";

  formattedDate = ReplaceWordInString(format, "dd", to_string(date.day));
  formattedDate = ReplaceWordInString(formattedDate, "mm", to_string(date.month));
  formattedDate = ReplaceWordInString(formattedDate, "yyyy", to_string(date.year));

  return formattedDate;
}

void printDate(stDate date)
{
  cout << "DAY: " << date.day << "\n"
       << "MONTH: " << date.month << "\n"
       << "YEAR: " << date.year << endl;
}

int main()
{
  stDate date1, date2;
  date1.year = 2000, date1.month = 15, date1.day = 25;
  date2.year = 2022, date2.month = 2, date2.day = 2;

  cout << formatDate(date1, "Day: dd\nyear: yyyy\nmonth: mm") << endl;

  return 0;
}