#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int sum_divisors(int n){
  int i;
  int sum = 0;
  for (i = 1; i < n; i++){
    if (!(n % i )){
      sum += i;
    }
  }
  return sum;
}

int main(int argc, char* argv[]){
  int i;
  int test;
  int sum = 0;
  for (i = 1; i < 10000; i++){
    test = sum_divisors(i);
    if (test != i &&sum_divisors(test) == i){
      sum += i;
    }
  }
  printf("%d\n", sum);
  return 0;
}
