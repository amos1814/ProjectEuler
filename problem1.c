#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){
  int i;
  int sum;
  for (i=0; i<1000; i++){
    if (!(i % 5) || !(i % 3)){
      sum += i;
    }
  }
  printf("%i\n", sum);
  return 0;
}
