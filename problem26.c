#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main(int argc, char* argv[]){
  int i;
  int value, count, max;
  int limit = 10000;
  
  int max_count = 0;
  for (i = 2; i<1000; i++){
    count = 0;
    limit = 10000;
    value = 10 % i;
    while (value != 1 && limit > 0){
      value = value *10;
      value = value % i;
      count++;
      limit--;
    }
    if (count > max_count && limit != 0){
      max_count = count;
      max = i;
    }
  }
  printf("%d %d\n",max, max_count);
  return 0;
}
