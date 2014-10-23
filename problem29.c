#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int power(int a, int b){
  int i;
  int result = 1;
  for (i = 0; i < b; i++){
    result *= a;
  }
  return result;
}

// number of multiples between 2 and 100 inclusive
int multiples(int n){
  int i;
  int counter = 0;
  for (i = 2*n; i <= 100; i += n){
    counter++;
  }
  return counter;
}

int duplicates(int n){
  int i, j;
  int result = 0;
  // note 10 ^2 = 100
  for (i = 2; i <= 10 && i < n; i++){
    
    // note 2^7 > 100
    for (j = 2; j < 7; j++){
      if (power(i, j) == n){
        result += multiples(j);
      }
    }
  }
  return result;
}

int main(int argc, char* argv[]){
  // The idea is to take all combinations and subtract duplicates.
  // Duplicates can be found by finding all roots of a number.
  int i;
  int dup = 0;
  for (i = 2; i <= 100; i++){
    dup += duplicates(i);
    printf("%d\n", duplicates(i));
  }
  printf("%d\n", 99 * 99 - dup + 1);
  return 0;
}
