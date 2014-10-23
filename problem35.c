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

int num_digits(int n){
  int i;
  float f = (float) n;
  for (i = 0; f >= 1; i++){
    f = f/10;
  }
  return i;
}

int rotate(int n){
  if (n < 10){
    return n;
  }
  int least = n % 10;
  if (least == 0){
    return n;
  }
  return least * pow(10, num_digits(n) - 1) + (n - least)/10;
}

int check_rotations(int n){
  int i;
  if (!(n % 2) || !(n % 3) || !(n % 5) || !(n % 7) || ! (n % 9)){
    return 0;
  }
  for (i = 0; i < num_digits(n); i++){
    n = rotate(n);
    if (!isPrime(n)){
      return 0;
    }
  }
  return 1;
}

int main(int argc, char* argv[]){
  int i;
  int counter = 4;
  for (i = 10; i < 1000000; i++){
    if (check_rotations(i)){
      printf("%d\n", i);
      counter += 1;
    }
  }
  printf("%d\n", counter);
  return 0;
}
