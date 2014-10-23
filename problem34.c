#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int factorial(int n)
{
  if (n == 1 || n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}

// test stops when sum exceeds number
int test(int n){
  int temp = n;
  int sum = 0;
  while (temp >= 1){
    sum += factorial(temp % 10);
    // printf("%d %d\n", temp, temp % 10);
    temp = (temp - (temp % 10)) / 10;
    if (sum > n){
      return 0;
    }
  }
  if (sum == n)
    return 1;
  return 0;
}

int main(int argc, char* argv[]){
  // Upper bound will be 9! * 7, since it has 7 digits.
  // This is bounded by 2550000.
  
  int i;
  long long int result = 0;
  for (i = 3; i < 2550000; i++){
    if (test(i)){
      printf("%d\n", i);
      result += i;
    }
  }
  printf("sum: %lld\n", result);
  
  return 0;
}
