#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int test(int a, int b, int c){
  return (a * a + b * b == c * c);
}

int solutions(int p){
  int a;
  int b;
  int c;
  int counter = 0;
  for (a = 1; a < ceil(p/2); a++){
    for (b = a; b < ceil(p/2); b++){
      c = p - b - a;
      if (test(a, b, c)){
        counter += 1;
      }
    }
  }
  return counter;
}

int main(int argc, char* argv[]){
  int max = 0;
  int max_value = 0;
  int current_value;
  int p;
  for (p = 3; p <= 1000; p++){
    current_value = solutions(p);
    if (current_value > max_value){
      max_value = current_value;
      max = p;
    }
  }
  printf("%d\n", max);
  
  return 0;
}
