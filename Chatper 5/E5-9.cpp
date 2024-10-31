#include <iostream>
using namespace std;

int daytab[2][13] = {
  {0,31,28,31,30,31,30,31,31,30,31,30,31},
  {0,31,29,31,30,31,30,31,31,30,31,30,31} // leap year with extra day
};

// daytab points to an array, and NOT the first element of daytab. To make it easier to pass
// daytab around, let's create a pointer that points to the first element of daytab. This way we
// can then use pointer math to navigate the daytab array

int * dtp = &daytab[0][0];


int day_of_year(int, int, int, int dt[2][13]);
void month_day(int, int, int *, int *);

int main()
{

  int year = 2020;
  int month = 4;
  int day = 29;

  int yearday = day_of_year(year, month, day, daytab);
  cout << "Day of year = " << yearday << endl;
  

  int whichMonth = 1, whichDay = 0;
  month_day(year, yearday, &whichMonth, &whichDay);
  cout << "Month = " << month << ", Day = " << day << endl;

}

int day_of_year(int year, int month, int day, int dt[2][13])
{
  int i, leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  // With multidimensional arrays, the name does not point to the first element like 1D arrays to. Instead, the 
  // name points to the entire 2D array. When we pass daytab into this function, we are passing a pointer to an 
  // array, not a pointer to the first index of that array. 
  // If we want to use pointer math, we need to explicitly create a pointer to point to the first spot of the array

  // it's important to note that 2D arrays are stored in contiguous blocks of memory. 
  // That is to say that p[0] = arr[0][0] and p[14] = arr[1][1]

  // dt points to daytab and daytab points to an entire 2D array, NOT the first element of daytab. We can't use dt for
  // point math. Let's create a pointer that very specifically points to the first element of the daytab, so now
  // we can use normal pointer maths on it.
  int * p = &dt[0][0];
  if (leap) p += 13; // set = to daytab[1][0]
  while (month > 0) { // we'll keep doing this until month goes to 0
    day += *p++;
    month--;
  }
  return day;

  // p.s. daytab is global
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  if (leap) dtp += 13; // if leap year, jump to second row of daytab

  for ( ; yearday > *dtp; dtp++, *pmonth++)
    yearday -= *dtp;

  *pday = yearday;
}