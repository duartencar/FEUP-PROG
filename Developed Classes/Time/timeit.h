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

    //constructor with all vars
    Timeit(unsigned int hours, unsigned int min, unsigned int secs, unsigned int milis);

    //returns HorM value
    bool getHorM() const;

    //sets HormValue to false
    void setHorM_toFalse();

    //sets HormValue to true
    void setHorM_toTrue();

    //Checks if time in the class is valid
    bool valid() const;

    //return 0 if equal, <0 if right bigger than this*
    int compare(const Timeit& right) const;

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

    //sets all classe members to 0
    void Reset();

    //Clones to_copy
    void Copy(const Timeit& to_copy);

    //returns a formated string with the hours
    string getTime();

  private:
    unsigned int hours;         //Hours value
    unsigned int minutes;       //Minutes value
    unsigned int seconds;       //Seconds value
    unsigned int miliseconds;   //Miliseconds value
    bool HorM;                  //If true, hours won t be ignored
};

  //returns tokens
  string get_token(string to_token, size_t begin, size_t end);

  //gets token posititions and returns them
  vector<string> tokenizer (string to_token, string token);

  //returns int tokens
  vector<int> int_tokenizer (string to_token, string token);

  /*Checks if string inserted by user is valid*/
  bool validAnswer(string answer, int type);

  //Returns true if left is equal to right, false if not
  bool operator == (const Timeit& left, const Timeit& right);

  //Returns true if left total time is more than right
  bool operator > (const Timeit& left, const Timeit& right);

  //Returns true if left total time is less than right
  bool operator < (const Timeit& left, const Timeit& right);

  //Copies the value on right, to left
  void operator << (const Timeit& left, const Timeit& right);

  //Copies the value on left, to right
  void operator >> (const Timeit& left, const Timeit& right);
