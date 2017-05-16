#include <iostream>
#include "date.h"

int main (void)
{
  Date a(2017, 5, 16);
  Date b("2016/02/29");
  Date c;

  c.setDate(2017,5,15);

  a.show();
  b.show();
  c.show();

  if(a.isValid())
    cout << "a - " << a.getDate() << " e uma data valida.\n";
  if(b.isValid())
    cout << "b - " << b.getDate() << " e uma data valida.\n";
  if(c.isValid())
    cout << "c - " << c.getDate() << " e uma data valida.\n";

  if(a == c)
    cout << "As datas sao iguais\n";
  else if(a != c)
  {
    if(a > c)
      cout << a.getDate() << " e uma data mais antiga que " << c.getDate() << endl;
    else
      cout << c.getDate() << " e uma data mais antiga que " << a.getDate() << endl;
  }

  return 0;
}
