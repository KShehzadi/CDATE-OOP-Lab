#include <iostream>
using namespace std;
class CDate{
private:
  int month, day, year;
  static int daysofMonth[12];
  static char strofmonth[12][4];
  static char stringofmonth[12][10];
public:
	CDate();
	CDate(int d, int m, int y);
	~CDate(){}
	CDate& setDay(int d);
	CDate& setMonth(int m);
	CDate& setYear(int y);
  int getday();
  int getmonth();
  int getyear();
  void print(int opt = 0);
  void Readfromkb();
  void validate();
  bool isleapyear()const;
  CDate& setDate(int d, int m, int y);
  int comparewithdate(CDate date);
  char* tostring()const;
  int operator <(CDate date)const;
  int operator <=(CDate date)const;
  int operator >(CDate date)const;
  int operator >=(CDate date)const;
  int operator ==(const CDate date)const;
  int operator !=(const CDate date)const;
  CDate& operator++();
  CDate operator++(int);
  CDate& operator--();
  CDate operator--(int);
  CDate operator +(CDate & m);
  CDate operator -(CDate & m);
  friend ostream& operator <<(ostream &output, const CDate &date);
  friend istream& operator >>(istream &input, CDate &date);
};
