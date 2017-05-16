#include "Bus.h"

Bus::Bus()
{
  orderInLine = -1;
  driverId = -1;
  lineId = -1;
  schedule.empty();
}

Bus::Bus(unsigned int order, unsigned int driver, unsigned int line)
{
  orderInLine = order;
  driverId = driver;
  lineId = line;
}

unsigned int Bus::getBusOrderInLine() const
{
  return orderInLine;
}

unsigned int Bus::getDriverId() const
{
  return driverId;
}

unsigned int Bus::getLineId() const
{
  return lineId;
}

vector<Shift> Bus::getSchedule() const
{
  return schedule;
}

void Bus::setDriverId(int newID)
{
  driverId = newID;
}

void Bus::setLineId(int newID)
{
  lineId = newID;
}

void Bus::setOrder(int newOrder)
{
  orderInLine = newOrder;
}
