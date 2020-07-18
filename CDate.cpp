#include "CDate.h"
#include <iostream>
#include <cstring>
using namespace std;
int  CDate::daysofMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char CDate::strofmonth[12][4] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
char CDate::stringofmonth[12][10] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
CDate::CDate(){day = 14; month = 8; year = 1947; validate();}
CDate::CDate(int d, int m, int y){
  day = d, month = m; year = y; validate();
}

void CDate::Readfromkb(){
  do{cout<< "\n \a Enter a date as dd mm yyyy :";cin>> day>> month>> year;validate();}while(day == -1);
}
void CDate::validate(){if(month < 1 || month > 12) day = -1; else{if(isleapyear())daysofMonth[1] = 29; else daysofMonth[1] = 28;}
if(day < 1 || day > daysofMonth[month - 1]) day = -1;}
bool CDate::isleapyear()const{
  if(year % 4 ) return 0;else return 1;
}
CDate& CDate::setDay(int d){day = d; validate();return *this;}
CDate& CDate::setYear(int y){year = y; validate(); return *this;}
CDate& CDate::setMonth(int m){month = m; validate(); return *this;}
CDate& CDate::setDate(int d, int m, int y){
  day = d, month = m; year = y; validate();
  return *this;
}
int CDate::getday()
{
  return day;
}
int CDate::getmonth()
{
  return month;
}
int CDate::getyear()
{
  return year;
}
void CDate::print(int opt)
{
  if(opt == 2)
  {
    cout<< stringofmonth[month - 1]<< " "<< day<< "," <<year <<"\n";
  }
  else if(opt == 1)
  {
    cout <<day << "-"<< strofmonth[month - 1]<< "-"<<year <<"\n";
  }
  else
  {
    cout<<day <<"/" <<month <<"/" <<year <<"\n";
  }
}
int CDate::comparewithdate(CDate date)
{
  if (year < date.year)
  {
    return -1;
  }
  if (year > date.year)
  {
    return 1;
  }
  if (month < date.month)
  {
    return -1;
  }
  if (month > date.month)
  {
    return 1;
  }
  if (day < date.day)
  {
    return -1;
  }
  if (day > date.day)
  {
    return 1;
  }
  return 0;
}
char* CDate::tostring()const{
  char pad[20];
  sprintf(pad, "%d / %d / %d", this->day, this->month, this->year);
  char *str = new char[strlen(pad) + 1];
  strcpy(str, pad);
  return str;
}
int CDate::operator <(CDate date)const
{
  if (this->year < date.year)
  {
    return 1;
  }
  if (this->year > date.year)
  {
    return 0;
  }
  if (this->month < date.month)
  {
    return 1;
  }
  if (this->month > date.month)
  {
    return 0;
  }
  if (this->day < date.day)
  {
    return 1;
  }
  return 0;
}

int CDate::operator <=(CDate date)const
{
  if (this->year < date.year)
  {
    return 1;
  }
  if (this->year > date.year)
  {
    return 0;
  }
  if (this->month < date.month)
  {
    return 1;
  }
  if (this->month > date.month)
  {
    return 0;
  }
  if (this->day <= date.day)
  {
    return 1;
  }
  return 0;
}

int CDate::operator >(CDate date)const
{
  if (this->year > date.year)
  {
    return 1;
  }
  if (this->year < date.year)
  {
    return 0;
  }
  if (this->month > date.month)
  {
    return 1;
  }
  if (this->month < date.month)
  {
    return 0;
  }
  if (this->day > date.day)
  {
    return 1;
  }
  return 0;
}

int CDate::operator >=(CDate date)const
{
  if (this->year > date.year)
  {
    return 1;
  }
  if (this->year < date.year)
  {
    return 0;
  }
  if (this->month > date.month)
  {
    return 1;
  }
  if (this->month < date.month)
  {
    return 0;
  }
  if (this->day >= date.day)
  {
    return 1;
  }
  return 0;
}

int CDate::operator ==(const CDate date)const
{
  if (this->year != date.year)
  {
    return 0;
  }
  if (this->month != date.month)
  {
    return 0;
  }
  if(this->day != date.day)
  {
    return 0;
  }
  return 1;
}

int CDate::operator !=(const CDate date)const
{
  if (this->year != date.year)
  {
    return 1;
  }
  if (this->month != date.month)
  {
    return 1;
  }
  if(this->day != date.day)
  {
    return 1;
  }
  return 0;
}
ostream & operator <<(ostream & output, const CDate & date)
{
  output<< date.day<< '/'<< date.month<< '/'<< date.year;
  return output;
}
istream& operator >>(istream & input, CDate & date)
{
  do{
    cout<< "\n \a Enter date as dd mm yyyy :";
    input>> date.day>> date.month>> date.year;
    date.validate();
  }while(date.day == -1);
  return input;
}
CDate& CDate::operator ++(){
  ++day;
  if(day > daysofMonth[month - 1])
  {
    day = 1;
    ++month;
    if(month > 12)
    {
      month = 1;
      year++;
    }
  }
  return *this;
}
CDate CDate::operator++(int){
  CDate temp(*this);
  ++day;
  if(day > daysofMonth[month - 1])
  {
    day = 1;
    ++month;
    if(month > 12)
    {
      month = 1;
      year++;
    }
  }
  return temp;
}
CDate& CDate::operator--()
{
  --day;
  if (day == 0)
  {
    --month;
    if(month == 0)
    {
      month = 12;
      day = daysofMonth[month - 1];
      --year;
    }
  }
  return *this;
}
CDate CDate::operator--(int)
{
  CDate temp(*this);
  --day;
  if (day == 0)
  {
    --month;
    if(month == 0)
    {
      month = 12;
      day = daysofMonth[month - 1];
      --year;
    }
  }
  return temp;

}
CDate CDate::operator +(CDate & m)
{
  CDate x;
  CDate y;
  CDate newdate;
  int i;
  if(this->year >= m.year)
  {
    x = *this;
    y = m;
  }
  else{
    x = m;
    y = *this;
  }
  i = x.year - y.year;
  newdate.year = y.year + i;
  newdate.month = x.month + y.month;
  if(newdate.month > 12)
  {
    newdate.year++;
    newdate.month = newdate.month - 12;
  }
  newdate.day = x.day + y.day;
  if(newdate.day > daysofMonth[newdate.month - 1])
  {
    newdate.day = newdate.day - daysofMonth[newdate.month - 2];
    newdate.month++;
  }
  return newdate;
}
CDate CDate::operator -(CDate & m)
{
  CDate newdate;
  int i;
  CDate x, y;
  if(this->year >= m.year)
  {
    x = *this;
    y = m;
  }
  else{
    x = m;
    y = *this;
  }
  i = x.year - y.year;
  newdate.year = y.year - i;
  newdate.month = x.month - y.month;
  if(newdate.month < 1)
  {
    newdate.year--;
    newdate.month = newdate.month + 12;
    newdate.day = x.day - y.day;
    if(newdate.day < 1)
    {
      newdate.day = daysofMonth[newdate.month - 1] + newdate.day;
      newdate.month--;
    }
  }
  return newdate;
}
