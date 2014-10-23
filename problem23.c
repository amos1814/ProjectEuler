#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int abundant(int n){
  int i;
  int sum = 0;
  for (i = 1; i < n; i++){
    if (!(n % i)){
      sum += i;
    }
  }
  if (sum > n)
    return 1;
  return 0;
}

int* list_abundant(int n){
  int* array;
  array = malloc((n + 1) * sizeof(int));
  int i;
  array[0] = 0;
  for (i = 1; i <= n; i++){
    array[i] = abundant(i);
    // printf("%d\n", abundant(i));
  }
  int* result = array;
  return result;
}

int* sumOfAbundants(int* array, int size){
  
  int i, j;
  int* a;
  a = malloc((size + 1) * sizeof(int));
  a[0] = 0;
  for (i = 1; i <= size + 1; i++){
    a[i] = 0;
  }

  int sum;
  for (i = 1; i <= size; i++){
    printf("%d\n", i);
    for (j = i; j <= size; j++){
      sum = i + j;
//    printf("%d %d %d %d %d\n", i, j, array[i], array[j], sum);
      if (array[i] > 0 && array[j] > 0 && sum <= size){
        a[i+j] = 1;
      }
    }
  }
  int* result = a;
  return result;
}

int main(int argc, char* argv[]){
  int* array = list_abundant(28123);
  int* sum = sumOfAbundants(array, 28123);
  int i;
  long long int result = 0;
  for (i = 1; i <= 28123; i++){
    if (!(sum[i])){
      result += i;
    }
  }
  printf("%lld\n", result);
  return 0;
}
