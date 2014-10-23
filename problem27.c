#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int isPrime(int n){
  int i;
  // printf("%lld \n", n);
  if (n < 2){
    return 0;
  }
  for (i = 2; i < n; i++){
    if ((n % i) == 0){
      //printf("found factor\n");
      return 0;
    }
  }
  return 1;
}

int consecutive(int a, int b){
  int i = 0;
  int test;
  while(1){
    test = i * i + a * i + b;
    if (!isPrime(test)){
      break;
    }
    i++;
  }
  return i;
}

int main(int argc, char* argv[]){
  int a;
  int b;
  int max_a = 0;
  int max_b = 0;
  int max_count = 0;
  int check;
  for (a = -999; a < 1000; a++){
    for (b = -999; b < 1000; b++){
      check = consecutive(a, b);
      if (check > max_count){
        max_count = check;
        max_a = a;
        max_b = b;
      }
    }
  }
  printf("%d %d %d %d\n",max_a, max_b, max_a * max_b, max_count);
  return 0;
}
