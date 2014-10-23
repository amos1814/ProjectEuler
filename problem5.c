#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int divides(int a, int b){
  if ((a % b))
    return 0;
  return 1;
}

int divides1to20(int n){
  int i;
  for (i = 1; i <= 20; i++){
    if (!divides(n, i)){
      return 0;
    }
  }
  return 1;
}

int main(int argc, char* argv[]){
  int i = 2520;
  while (1){
    if (divides1to20(i)){
      printf("%d\n", i);
      exit(0);
    }
    i += 20;
  }
  return 0;
}
