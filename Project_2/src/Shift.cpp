#include "Shift.h"

Shift::Shift()
{
  busLineId = -1;

  driverId = -1;

  busOrderNumber = -1;

  startTime = -1;

  endTime = -1;
}

Shift::Shift(unsigned int linha, unsigned int condutor, unsigned int autocarro, unsigned int inicio, unsigned int fim)
{
  busLineId = linha;

  driverId = condutor;

  busOrderNumber = autocarro;

  startTime = inicio;

  endTime = fim;
}

unsigned int Shift::getBusLineId() const
{
  return busLineId;
}

unsigned int Shift::getDriverId() const
{
  return driverId;
}
unsigned int Shift::getBusOrderNumber() const
{
  return busOrderNumber;
}

unsigned int Shift::getStartTime() const
{
  return startTime;
}

unsigned int Shift::getEndTime() const
{
  return endTime;
}

void Shift::setBusLineId(unsigned int busLineId)
{
  this->busLineId = busLineId;
}

void  Shift::setDriverId(unsigned int driverId)
{
  this->driverId = driverId;
}

void Shift::setBusOrderNumber(unsigned int busOrderNumber)
{
  this->busOrderNumber = busOrderNumber;
}

void Shift::setStartTime(unsigned int startTime)
{
  this->startTime = startTime;
}

void Shift::setEndTime(unsigned int endTime)
{
  this->endTime = endTime;
}

unsigned int Shift::duration()
{
  return endTime - startTime;
}

string Shift::convertToHours(unsigned int to_convert)
{
  char converted[6];

  int hours = to_convert / 60;

  int min = to_convert % 60;

  sprintf(converted, "%02d:%02d", hours, min);

  string to_return(converted);

  return to_return;
}

void Shift::printShift()
{
  cout << "|" << right << setw(3) << busLineId << "|" << setw(2) << right << busOrderNumber << "|" << setw(3) << driverId << "|" << setw(5) << convertToHours(startTime) << "|" << setw(5) << convertToHours(endTime) << "|";
}
