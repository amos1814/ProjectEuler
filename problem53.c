#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <gmp.h>


// 100^100 has 200 digits, so we will use that size of the array
mpz_t factorial(mpz_t n){
  int *array;
  if (n == 0){
    array = calloc(sizeof(int), 200);
    array[0] = 1;
  }
  return mult(factorial(n - 1), n);
}

long long int choose(int n, int m){
  long long int num = factorial(n);
  printf("%lld\n", num);
  long long int denom = factorial(m) * factorial(n - m);
  printf("%lld\n",denom);
  return num/denom;
}

// This counts the value we want for a single number.
int over_million(int n){
  int i;
  int counter = 0;
  for (i = 2; i < n; i++){
    if (choose (n, i) > 1000000){
      counter++;
    }
  }
  return counter;
}

int main(int argc, char* argv[]){
  // printf("%d\n", over_million(23));
  int i;
  int counter = 0;
  for (i = 23; i <= 100; i++){
    counter += over_million(i);
  }
  printf("total: %d\n", counter);
  return 0;
}
