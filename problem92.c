#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int num_digits(int n){
  int i;
  float f = (float) n;
  for (i = 0; f >= 1; i++){
    f = f/10;
  }
  return i;
}

int nthdigit(int x, int n)
{
  while (n--) {
    x /= 10;
  }
  return (x % 10);
}

// sum of squares of digits;
int next(int n){
  int d = num_digits(n);
  int i;
  int nth;
  int sum = 0;
  for (i = 0; i < d; i++){
    nth = nthdigit(n, i);
    sum += (nth * nth);
  }
  return sum;
}

// Does the chain end in 1 or 89
int end(int n){
  int current = n;
  while(current != 1 && current != 89){
    current = next(current);
  }
  return current;
}

int main(int argc, char* argv[]){
  int i;
  int counter = 0;
  for (i = 1; i <10000000; i++){
    if (!(i % 100000)){
      printf("%d %d\n", i, counter);
    }
    if (end(i) == 89){
      counter++;
    }
  }
  printf("%d\n", counter);
  return 0;
}
