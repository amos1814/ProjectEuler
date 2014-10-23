#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


//Also tests if it doesnt contain 0
int duplicate(char* string){
  int i, j;
  
  for (i = 0; i < strlen(string); i++){
    if (string[i] == '0'){
      return 1;
    }
  }
  
  for (i = 0; i < strlen(string) - 1; i++){
    for (j = i+1; j < strlen(string); j++){
      if (string[i] == string[j]){
        return 1;
      }
    }
  }
  return 0;
}


int test(int a[5], int n){
  int test11 = (a[0]*10 + a[1]);
  int test12 = (a[2]*100 + a[3]*10 + a[4]);
  int test21 = a[0];
  int test22 = (a[1]*1000 + a[2]*100 + a[3]*10 + a[4]);
  // printf("%d: %d * %d, %d * %d\n", n, test11, test12, test21, test22);
  if ((test11 * test12 == n) || (test21 * test22 == n)){
    return 1;
  }
  return 0;
}


void swap(int* a, int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

int testall(int* a, int i, int k, int n) {
  int j;
  for (j = i; j <= k; j++) {
    swap(a, j, i);
    if (testall(a, i + 1, k, n)){
      return 1;
    }
    swap(a, i, j);
  }
  if(i == k) {
    if (test(a, n)){
      printf("found one\n");
      return 1;
    }
  }
  return 0;
}



// Is there a solution for this number?
int pandigital(int n){
  
  int* array = calloc(sizeof(int), 9);
  int remaining[5];
  int i;
  int digit;
  char* stringform = calloc(sizeof(char), 10);
  sprintf(stringform,"%d", n);
  
  if (duplicate (stringform)){
    return 0;
  }
  
  for (i = 0; i < strlen(stringform); i++){
    digit = stringform[i] - '0';
    // printf("*%d *", digit);
    array[digit - 1] = 1;
  }
  
  int j = 0;
  for (i = 0; i < 9; i++){
    if (!array[i]){
      remaining[j] = i + 1;
      j++;
    }
  }
  // printf("%d\n", n);
  
  // call testall on remaining
  int result = testall(remaining, 0, 4, n);
  printf("%d\n", result);
  return result;
}

int main(int argc, char* argv[]){
  // Consider numbers between 1000 and 9999.
  // Note 99 x 99 = 9801
  // So cases will be:
  // 2digit x 3digit = 4digit
  // 1digit x 4digit = 4digit
  
  int n;
  int sum = 0;
  for (n = 1000; n < 10000; n++){
    if(pandigital(n)){
      printf("%d\n", n);
      sum += n;
    }
  }
  
  printf("%d\n", sum);
  
  return 0;
}
