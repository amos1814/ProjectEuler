#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int isPrime(long long int n){
  int i;
  // printf("%lld \n", n);
  if (n < 2 || !(n % 2)){
    return 0;
  }
  int max = ceil((int)sqrtl(n));
  for (i = 2; i <= max; i++){
    if ((n % i) == 0){
      //printf("found factor\n");
      return 0;
    }
  }
  return 1;
}

int main(int argc, char* argv[]){
  long long int entry = 1;
  int num_primes = 0;
  int layer = 0;
  int i;
  int tracker = 1000000;
  double ratio = 1;
  while (ratio >= 0.10){
    layer++;
    for (i = 0; i < 4; i++){
      entry += 2 * layer;
      num_primes += isPrime(entry);
      //printf("%lld %d\n", entry, isPrime(entry));
    }
    ratio = ((double) num_primes)/ (4 * layer + 1);
    // printf("%d %lld ratio: %f\n", num_primes, entry, ratio);
    if ((entry > tracker)){
      printf("layer:%d primes:%d size:%lld ratio: %f\n", layer, num_primes, entry, ratio);
      tracker += 1000000;
    }
  }
  printf("side length: %d\n", layer * 2 + 1);
  return 0;
}
