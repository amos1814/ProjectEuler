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

int nextPrime(int prime){
  int i;
  for (i = prime + 1; ; i++){
    if (isPrime(i)){
      return i;
    }
  }
  return 0;
}



int main(int argc, char* argv[]){
  int start;
  int max = 0;
  int max_start;
  int max_count = 0;
  int counter;
  int sum;
  int i;
  // We don't cache the results
  // But set the limit start * max_count < 1000000
  // The program will finish quickly enough
  for (start = 0; start * max_count < 1000000; start = nextPrime(start)){
    printf("%d %d\n", start, max_count);
    sum = 0;
    counter = 0;
    for (i = nextPrime(start); sum < 1000000; i = nextPrime(i)){
      sum += i;
      counter += 1;
      if (isPrime(sum) && counter > max_count){
        max = sum;
        max_count = counter;
        max_start = start;
      }
    }
  }
  printf("%d\n", max);
  return 0;
}
