#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int* num_to_array(int n){
  int num_digits;
  int temp = n;
  for (num_digits = 0; temp >= 1; num_digits++){
    temp /= 10;
  }
  
  int* array = calloc(sizeof(int), 10);
  
  int i;
  int digit;
  temp = n;
  for (i = 0; i < num_digits; i++){
    digit = temp % 10;
    //printf("%d\n", digit);
    temp = (temp - digit)/10;
    // printf("%d %d\n", temp, digit);
    array[i] = digit;
  }
  return array;
}

int main(int argc, char* argv[]){
  int num;
  
  int i;
  int sum = 0;
  int total_sum = 0;
  int* array;
  for (num = 2; num < 1000000; num++){
    sum = 0;
    array = num_to_array(num);
    for (i = 0; i < 10; i ++){
      sum += pow(array[i], 5);
    }
    if (sum == num){
      printf("%d\n", num);
      total_sum += num;
    }
  }
  printf("%d\n", total_sum);
  return 0;
}
