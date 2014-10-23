#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){
  int f1 = 1;
  int f2 = 2;
  int next;
  int sum = 2;
  while (next <= 4000000){
    next = f1 + f2;
    if (!(next % 2))
      sum += next;
    f1 = f2;
    f2 = next;
  }
  printf("%i\n", sum);
  return 0;
}
