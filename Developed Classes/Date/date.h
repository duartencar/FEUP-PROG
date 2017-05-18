#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <time.h>

using namespace std;

class Date
{
  public:
    //Default Constructor -> Gets date of the current day
    Date();

    //Constructor with numbers
    Date(unsigned int year, unsigned int month,unsigned int day);

    //Constructor with strings yearMonthDay must be in format "yyyy/mm/dd"
    Date(string yearMonthDay);

    //Returns true if dates are equal, false if they dont
    int compare(const Date& right) const;

    //Changes year value
    void setYear(unsigned int year);

    //Changes month value
    void setMonth(unsigned int month);

    //Changes day value
    void setDay(unsigned int day);

    //Changes all date values
    void setDate(unsigned int year, unsigned int month, unsigned int day);

    //returns year
    unsigned int getYear() const;

    //returns month
    unsigned int getMonth() const;

    //returns day
    unsigned int getDay() const;

    //returns the date in format "yyyy/mm/dd"
    string getDate() const;

    //shows the date on the screen in format "yyyy/mm/dd"
    void show();

    //returns true if date is valid, false if doesnt
    bool isValid();
  private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int maxMonthDays();
    bool biSsexto();
};

  //returns true if the dates are equal, false if they dont
  bool operator == (const Date& left, const Date& right);

  //returns true if dates are different, false if they dont
  bool operator != (const Date& left, const Date& right);

  //returns true if left is older than right
  bool operator>(const Date& left, const Date& right);

  //returns true if right is older than left
  bool operator<(const Date& left, const Date& right);

  //returns tokens
  string get_token(string to_token, size_t begin, size_t end);

  //gets token posititions and returns them
  vector<string> tokenizer (string to_token, string token);

  //returns int tokens
  vector<int> int_tokenizer (string to_token, string token);

  /*Checks if string inserted by user is valid*/
  bool validAnswer(string answer, int type);
