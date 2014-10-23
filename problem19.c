#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int isSunday(int day){
  if (day % 7 == 5){
    return 1;
  }
  return 0;
}

int main(int argc, char* argv[]){
  int num_days = 99 * 365 + 25;
  int day = 0;
  int year = 1901;
  
  int count = 0;
  while (day <= num_days){
    // Jan
    count += isSunday(day);
    day += 31;

    
    // Feb
    count += isSunday(day);
    if (!(year % 4)){
      day += 29;
    } else {
      day += 28;
    }
    
    // Mar
    count += isSunday(day);
    day += 31;
    
    // Apr
    count += isSunday(day);
    day += 30;
    
    // May
    count += isSunday(day);
    day += 31;

    // Jun
    count += isSunday(day);
    day += 30;
    
    // Jul
    count += isSunday(day);
    day += 31;
    
    // Aug
    count += isSunday(day);
    day += 31;
    
    // Sep
    count += isSunday(day);
    day += 30;
    
    // Oct
    count += isSunday(day);
    day += 31;
    
    // Nov
    count += isSunday(day);
    day += 30;
    
    // Dec
    count += isSunday(day);
    day += 31;
    
    year ++;
  }
  
  printf("%d\n", count);
  return 0;
}
