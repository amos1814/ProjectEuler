#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

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

int pandigital(char* intstring){
  int len = strlen(intstring);
  int i, j;
  for (i = 0; i < len; i++){
    if (intstring[i] == '0' || (intstring[i] - '0' > len)){
      return 0;
    }
  }
  for (i = 0; i < len - 1; i++){
    for (j = i + 1; j < len; j++){
      if (intstring[i] == intstring[j]){
        return 0;
      }
    }
  }
  return 1;
}

char* toString(int n){
  char* result = malloc(10);
  sprintf(result, "%d", n);
  return result;
}

int main(int argc, char* argv[]){
  int i;
  int max = 0;
  for (i = 2143; i <= 99999999; i++){
//    if (! (i % 100000)){
//      printf("%d\n", i);
//    }
    if (!(i % 2) || !(i % 3) || !(i % 5) || !(i % 7)){
      continue;
    }
    if (pandigital(toString(i))){
      if (isPrime(i)){
        max = i;
        printf("found %d\n", i);
      }
    }
  }
  printf("max: %d\n", max);
  return 0;
}
