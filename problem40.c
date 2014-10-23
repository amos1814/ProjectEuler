#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int num_digits(int n){
  int i;
  float f = (float) n;
  for (i = 0; f >= 1; i++){
    f = f/10;
  }
  return i;
}

int nthdigit(int x, int n)
{
  while (n--) {
    x /= 10;
  }
  return (x % 10);
}

int main(int argc, char* argv[]){
  
  int total_digits = 0;
  int n;
  int i;
  int find = 1;
  int result;
  int digit;
  int product = 1;
  for (i = 1; find <= 1000000; i++){
    n = num_digits(i);
    //printf("%d %d\n", n, i);
    total_digits += n;
    if (total_digits >= find){
      result = total_digits - find;
      digit = nthdigit(i, result);
      printf("%d %d %d\n", i, result, digit);
      product *= digit;
      fflush(stdout);
      find *= 10;
    }
  }
  printf("%d\n", product);
  return 0;
}
