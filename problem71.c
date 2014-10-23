#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct frac{
  int num;
  int denom;
} frac;

int reducible(frac* f){
  int i;
  int num = f->num;
  int denom = f->denom;

  for (i = 2; i < num; i++){
    if (!(num % i) && !(denom % i)){
      return 1;
    }
  }
  return 0;
}

int frac_gt(frac* f1, frac* f2){
  if (((double) f1->num)/ f1->denom > ((double) f2->num)/ f2->denom){
    return 1;
  }
  return 0;
}

int main(int argc, char* argv[]){
  // We want to keep track of the largest irreducible fraction
  // that is still less than 3/7
  
  frac* largest = (frac*) malloc(sizeof(frac));
  largest->num = 1;
  largest->denom = 3;
  frac* current = (frac*) malloc(sizeof(frac));
  frac* compare = (frac*) malloc(sizeof(frac));
  compare->num = 3;
  compare->denom = 7;
    
  int d;
  int n;
  for (d = 2; d <= 1000000; d++){
    if (!(d % 100)){
      //printf("Current denominator: %d\n", d);
    }
    for (n = floor(d * 3/7); n < d; n++){
      current->num = n;
      current->denom = d;
      // Go to next denominator if greater than 3/7
      if (!frac_gt(compare, current)){
        break;
      }
      if (!reducible(current) && frac_gt(current, largest)){
        largest->num = current->num;
        largest->denom = current->denom;
        printf("New max: %d %d\n", largest->num, largest->denom);
      }
    }
  }
  printf("Result: %d/%d\n", largest->num, largest->denom);
  return 0;
}
