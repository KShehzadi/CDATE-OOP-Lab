#include "CDate.h"
#include <iostream>
using namespace std;

int main()
{

  CDate date(14, 2, 2000);
  CDate dob(28, 12, 1999);
  CDate my;
  my = dob + date;
  cout<< my<< endl;
  my = date + dob;
  cout<< my<< endl;
  my = dob - date;
  cout<< my<< endl;
  my = date - dob;
  cout<< my<< endl;
  cin>> date;
  cout<< date;
  if(date > dob)
  {
    cout<< "hello"<< endl;
  }
  if(dob < date)
  {
    cout<< "good"<< endl;
  }
  if(date == date)
  {
    cout<< "cool"<< endl;
  }
  if(dob != date)
  {
    cout<< "fantastic"<< endl;
  }
  date.setDate(2, 12, 1999).print();
  date.print(2);
  date.Readfromkb();
  cout<< date++<< endl;
  cout<< date<< endl;
  cin>> date;
  cout<< ++date<< endl;
  cout<< date<< endl;
  cin>> date;
  cout<< date--<< endl;
  cout<< date<< endl;
  cin>> date;
  cout<< --date<< endl;
  cout<< date<< endl;
  cin>> date;
  date.print(2);
  date.print();
  date.print(1);
  date.setDay(14);
  date.print(2);
  date.setDay(90);
  date.print(0);
  date.setDay(02);
  date.setMonth(12);
  date.print();
  date.setMonth(90);
  date.print();
  date.setDate(14, 2, 2000);
  date.print(2);
  date.setDate(90, 20, 2000);
  date.print(2);
}
