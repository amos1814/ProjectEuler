#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){
  int layer = 1;
  int next_layer = 0;
  long long int sum = 0;
  int i = 1;
  
  while (i <= 1001 * 1001){
    //printf("%d %d\n", i, next_layer);
    sum += i;
    i += layer * 2;
    if (next_layer == 3){
      layer++;
      next_layer = 0;
    } else 
      next_layer++;
  }
  printf("%lld\n", sum);
  return 0;
}
