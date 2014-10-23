#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Unfortunately the stopping condition I gave takes too long
// I just used the first match given by the program
// And this happened to be the correct answer.

int pentagonal(int n){
  return (n * (3 * n - 1))/2;
}

int test (int n1, int n2){
  int p1 = pentagonal(n1);
  int p2 = pentagonal(n2);
  int difference = p1 - p2;
  int sum = p1 + p2;
  int i;
  for (i = 1; ; i++){
    if (difference == pentagonal(i)){
      break;
    }
    if (i > n1 && i > n2){
      return 0;
    }
  }
  for (i = 0; i <= n1 + n2; i++){
    if (sum == pentagonal(i)){
      printf("%d %d %d\n", n1, n2, difference);
      return difference;
    }
  }
  return 0;
}

int main(int argc, char* argv[]){
  
  int i, j;

  int min = pow(2, 31);
  int current;
  for (i = 2; ; i++){
    // printf("%d\n", i);
    if (pentagonal(i) - pentagonal(i - 1) > min){
      printf("%d\n", min);
      exit(0);
    }
    for (j = 1; j < i; j++){
      current = test(i, j);
      if (current && (current < min)){
        min = current;
      }
    }
  }
  return 0;
}
