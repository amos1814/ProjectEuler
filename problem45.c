#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//long long int triangle(int m){
//  long long int n = m;
//  return (n * (n+1))/2;
//}

long long int pentagonal(int m){
  long long int n = m;
  return (n * (3 * n - 1))/2;
}

// hexagonals are triangles
// n * (2n - 1) = m * (m+1)/2 
// m = 2n - 1;

long long int hexagonal(int m){
  long long int n = m;
  return n * (2 * n - 1);
}

int main(int argc, char* argv[]){
  int i, j;
  long long int h, p;
  for (i = 144; ; i++){
    h = hexagonal(i);
    for (j = 165; ; j++){
      p = pentagonal(j);
      if (p > h){
        break;
      }
      if (p == h){
        printf("%lld\n", h);
        exit(0);
      }
    }
  }
  return 0;
}
