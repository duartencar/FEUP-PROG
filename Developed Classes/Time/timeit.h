#pragma once

#include <iostream>
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

  private:
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
    unsigned int miliseconds;
};
