#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void addPrime(int *array, int size){
  int i = array[size - 1] + 1;
  int j;
  int notprime;
  while(1){
    notprime = 0;
    for (j = 0; j < size; j++){
      if (!(i % array[j])){
        notprime = 1;
      }
    }
    if (!notprime){
      array[size] = i;
      return;
    }
    i++;
  }
}

int main(int argc, char* argv[]){
  int* array = (int*)calloc(10001, sizeof(int));
  array[0] = 2;
  int i;
  for (i = 1; i < 10001; i++){
    addPrime(array, i);
  }
  printf("%d\n", array[10000]);
  return 0;
}
