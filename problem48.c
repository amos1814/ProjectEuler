#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// only need to keep track of last 10 digits
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
//  for (i = 9; i >=0; i--){
//    printf("%d", array[i]);
//  }
//  printf("\n");
}

int* self_exp(int n){
  int* array = calloc(sizeof(int), 10);
  int i;
  int stay;
  int current = n;
  for (i = 0; i < 10; i++){
    stay = current % 10;
    array[i] = stay;
    current = (current - stay)/10;
  }
  for (i = 0; i < n - 1; i++){
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

void print_self_exp(int n){
  int* array = self_exp(n);
  int i;
  for (i = 9; i >= 0; i--){
    printf("%d", array[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[]){
  int i;
  int* array = calloc(sizeof(int), 10);
  int* temp;
  print_self_exp(12);
  for (i = 1; i <= 1000; i++){
    temp = self_exp(i);
    add(array, temp);
  }
  for (i = 9; i >=0; i--){
    printf("%d", array[i]);
  }
  printf("\n");
  return 0;
}
