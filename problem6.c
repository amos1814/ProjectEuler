#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int sumSquares(int n){
  int i;
  int sum = 0;
  for (i=1; i <= n; i++){
    sum += (i * i);
  }
  return sum;
}

int squareSum(int n){
  int i;
  int sum = 0;
  for (i=1; i <= n; i++){
    sum += i;
  }
  return (sum * sum);
}

int main(int argc, char* argv[]){
  printf("%d\n", squareSum(100));
  printf("%d\n", sumSquares(100));
  printf("%d\n", squareSum(100) - sumSquares(100));
  return 0;
}
