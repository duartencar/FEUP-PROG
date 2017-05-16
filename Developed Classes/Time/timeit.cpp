#include "timeit.h"

Timeit::Timeit()
{
  hours = 0;
  minutes = 0;
  seconds = 0;
  miliseconds = 0;
}

Timeit::Timeit(float rawTime)
{
  if(rawTime >= 3600)
  {
    hours = (unsigned int)((float)rawTime / 3600);

    rawTime -= hours * 3600;
  }
  else
    hours = 0;

  if(rawTime >= 60)
  {
    minutes = (unsigned int)((float)rawTime / 60);

    rawTime -= minutes * 60;
  }
  else
    minutes = 0;

  if(rawTime >= 1)
  {
    seconds = (unsigned int)rawTime;

    rawTime -= seconds;
  }
  else
    seconds = 0;

  miliseconds = rawTime * 1000;
}

bool Timeit::valid() const
{
  if(hours < 0 || hours > 99)
    return false;

  if(minutes < 0 || minutes > 60)
    return false;

  if(seconds < 0 || seconds > 60)
    return false;

  if(miliseconds < 0 || miliseconds > 1000)
    return false;

  return true;
}

unsigned int Timeit::getHours() const
{
  return hours;
}

unsigned int Timeit::getMinutes() const
{
  return minutes;
}

unsigned int Timeit::getSeconds() const
{
  return seconds;
}

unsigned int Timeit::getMiliSeconds() const
{
  return miliseconds;
}

void Timeit::setHours(unsigned int hours)
{
  this->hours = hours;
}

void Timeit::setMinutes(unsigned int minutes)
{
  this->minutes = minutes;
}

void Timeit::setSeconds(unsigned int seconds)
{
  this->seconds = seconds;
}

void Timeit::setMiliSeconds(unsigned int miliseconds)
{
  this->miliseconds = miliseconds;
}
