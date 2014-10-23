#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int collatz(int n){
  long long int current = n;
  int count = 0;
  while(current > 1){
    if (current % 2){
      current += 2 * current + 1;
    } else {
      current = current/2;
    }
    count++;
  }
  return count + 1;
}

int main(int argc, char* argv[]){
  printf("%d\n", collatz(13));
  fflush(stdout);
  int i;
  int current_max = 0;
  int current_collatz = 0;
  for (i = 1; i < 1000000; i++){
    int c = collatz(i);
    if (c > current_collatz){
      current_max = i;
      current_collatz = c;
    }
  }
  printf("%d\n", current_max);
  return 0;
}
