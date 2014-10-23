#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int isPrime(int n){
  int i;
  for (i = 2; i * i <= n; i++){
    if ((n % i) == 0){
      return 0;
    }
  }
  return 1;
}

int main(int argc, char* argv[]){
  long long int sum = 0;
  int i;
  for (i = 2; i < 2000000; i++){
    if (isPrime(i)){
      sum += i;
    }
  }
  printf("%lld\n", sum);
  return 0;
}
