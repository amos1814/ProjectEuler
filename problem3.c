#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long long int isPrime(long long int n){
  long long int i;
  printf("%lld \n", n);
  for (i = 2; i < n; i++){
    if ((n % i) == 0){
      printf("found factor\n");
      return 0;
    }
  }
  return 1;
}

int main(int argc, char* argv[]){
  unsigned long long i;
  unsigned long long num = 600851475143;
  
  for (i=2; i < num; i++){
    if (!(num % i) && isPrime(num/i)){
      printf("%lld \n", num/i);
      exit(1);
    }
  }
  return 0;
}
