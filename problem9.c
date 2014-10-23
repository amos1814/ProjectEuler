#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){
  int a;
  int b;
  for (a = 1; a < 1000; a++){
    for (b = a; b < 1000; b++){
      if (a * a + b * b == (1000 - a - b) * (1000 - a - b)){
        printf("%d\n", a * b * (1000 - a - b));
        exit(0);
      }
    }
  }
  return 0;
}
