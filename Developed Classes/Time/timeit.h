#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Timeit
{
  public:
    //default construct
    Timeit();

    //constructor with float time
    Timeit(float rawTime);

    //constructor with string
    Timeit(string rawTime);

    //Checks if time in the class is valid
    bool valid() const;

    //returns hours value
    unsigned int getHours() const;

    //returns minutes value
    unsigned int getMinutes() const;

    //returns seconds value
    unsigned int getSeconds() const;

    //returns miliseconds value
    unsigned int getMiliSeconds() const;

    //changes hours value
    void setHours(unsigned int hours);

    //changes minutes value
    void setMinutes(unsigned int minutes);

    //changes seconds value
    void setSeconds(unsigned int seconds);

    //changes miliseconds value
    void setMiliSeconds(unsigned int miliseconds);

    //returns a formated string with the hours
    string getTime();

  private:
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
    unsigned int miliseconds;
};

  //returns tokens
  string get_token(string to_token, size_t begin, size_t end);

  //gets token posititions and returns them
  vector<string> tokenizer (string to_token, string token);

  //returns int tokens
  vector<int> int_tokenizer (string to_token, string token);

  /*Checks if string inserted by user is valid*/
  bool validAnswer(string answer, int type);
