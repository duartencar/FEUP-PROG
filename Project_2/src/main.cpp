#include <iostream>
#include "ui.hpp"
#include "Company.h"
#include "Line.h"
#include "Driver.h"
#include "Shift.h"

int main()
{
  vector<string> files;

  files = getFilesName();

  Company f("STCP", files[0], files[1]);

  while(Interface(f));

  return 0;
}
