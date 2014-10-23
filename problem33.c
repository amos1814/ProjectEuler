#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int equals(double a, double b){
  if ((a - b) < 0.000001 && (a - b) > -0.000001){
    return 1;
  }
  return 0;
}

int test(double a, double b, double c){
  return equals((10 * a + b)/(10 * b + c), a / c);
}

int main(int argc, char* argv[]){
  // We are looking for quotients of the form
  // ab/bc = ac, where a, b, and c are digits.
  double result = 1;
  
  double a;
  double b;
  double c;
  for (a = 1; a < 10; a++){
    for (b = 1; b < 10; b++){
      for (c = 1; c < 10; c++){
        if (b != c && test(a, b, c)){
          printf("%lf %lf %lf\n", a, b, c);
          result *= a/c;
        }
      }
    }
  }
  printf("%lf\n", result);
  return 0;
}
