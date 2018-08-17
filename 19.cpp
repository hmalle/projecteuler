/*
You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include<iostream>
using namespace std;

bool leap_year( int year){
  if (year%100 == 0 and year %4 == 0)
      return false;
  else if (year%4 == 0  and year%100!=0) 
    return true;
  else 
    return false;
}


int main()
{  
  int date=1, month=1, dow=1, sunday_the_first=0;
  for ( int year=1900; year<2001; ) {
    if(month==2 and leap_year(year) and date==30) {
      date = 1;
      month =3;
    }else if (date==29 and month==2 and !leap_year(year)) {
      date = 1;
      month = 3;
    }else if (date==31 and (month==4 or month == 6 or month ==9 or month==11)) {
      month +=1; 
      date = 1;
    }else if(date==32 and (month==1 or month==3 or month==5 or month==7 or month==8 or month==10)){
      month+=1;
      date = 1;
    }
    else if(date==32 && month == 12 ) {
      month = 1;
      date = 1;
      year+=1;
    }else {
      date+=1;
      dow+=1;
    }
    //***********************************
    if (date!=32 ){
      if ( dow%7 ==0  and date==1 and year>1900 and year<2001 )
        sunday_the_first+=1;
    }
  }
  cout<<sunday_the_first<<endl;
  return 0;
}
