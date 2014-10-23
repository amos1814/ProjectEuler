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

int test(int composite){
  int i;
  for (i = 1; 2 * i * i < composite; i++){
    if (isPrime(composite - 2 * i * i)){
      printf("%d\n", i);
      return 1;
    }
  }
  return 0;
}

int main(int argc, char* argv[]){
  int i;
  for (i = 33; ; i++){
    if (!isPrime(i) && (i % 2)){
      if (!test(i)){
        printf("%d\n", i);
        exit(0);
      }
    }
  }
  return 0;
}
