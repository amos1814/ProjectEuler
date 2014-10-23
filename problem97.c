#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// use code from #48

void mult(int* array, int n){
  int carry = 0;
  int stay;
  int prod;
  int i;
  for (i = 0; i < 10; i++){
    prod = n * array[i] + carry;
    stay = prod % 10;
    array[i] = stay;
    carry = (prod - stay)/10;
  }
}

int* expo(int n, int m){
  int* array = calloc(sizeof(int), 10);
  int i;
  int stay;
  int current = 1;
  for (i = 0; i < 10; i++){
    stay = current % 10;
    array[i] = stay;
    current = (current - stay)/10;
  }
  for (i = 0; i < m; i++){
    mult(array, n);
  }
  return array;
}

void add(int* array1, int* array2){
  int i;
  int carry = 0;
  int stay;
  int sum;
  for (i = 0; i < 10; i++){
    sum = array1[i] + array2[i] + carry;
    stay = sum % 10;
    array1[i] = stay;
    carry = (sum - stay)/10;
  }
}

int main(int argc, char* argv[]){
  int i;
  int* array = calloc(sizeof(int), 10);
  int* add1 = calloc(sizeof(int), 10);
  add1[0] = 1;
  array = expo(2, 7830457);
  mult(array, 28433);
  add(array, add1);
  for (i = 9; i >=0; i--){
    printf("%d", array[i]);
  }
  printf("\n");
  return 0;
}
