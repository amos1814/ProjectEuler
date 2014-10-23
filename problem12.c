#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long long int triangular(int n){
  int i;
  long long int sum = 0;
  for (i = 0; i <= n; i++){
    sum += i;
  }
  return sum;
}

int num_divisors(long long int n){
  int count = 0;
  long long int i;
  for (i = 1; i * i < n; i++){
    if (!(n % i)){
      count+= 2;
    }
  }
  if (i * i == n){
    count++;
  }
  return count;
}

int main(int argc, char* argv[]){
  long long int current;
  int i = 1;
  while(1){
    current = triangular(i);
    printf("%lld\n", current);
    if (num_divisors(current) > 500){
      printf("%lld\n", current);
      exit(0);
    }
    i++;
  }
  return 0;
}
