#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int test(char* permutation, int array[7]);
int test_all(char* a, int i, int k, int array[7]);

char* toString(int n){
  char* result = malloc(10);
  sprintf(result, "%d", n);
  return result;
}

long long int toInt(char* string){
  int len = strlen(string);
  int pow10 = 1;
  int i;
  long long int sum = 0;
  for (i = 0; i < len; i++){
    sum += (string[len - i - 1] - '0') * pow10;
    pow10 *= 10;
  }
  return sum;
}

void swap(char* a, int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

int test_all(char* a, int i, int k, int array[7]) {
  int j;
  for (j = i; j <= k; j++) {
    if (test_all(a, i + 1, k, array)){
      return 1;
    }
    swap(a, i, j);
  }
  if(i == k) {
    if (test(a, array)){
      printf("found one\n");
    }
  }
  return 0;
}

// get the nth 3 digit integer substring
int get_sub(long long int num, int n){
  if (n < 0 || n > 6){
    return 0;
  }
  int divide = num / (pow(10, 6 - n));
  return divide % 1000;
}

// test a single permutation of the digits
int test(char* permutation, int array[7]){
  int i;
  // we don't want leading 0
  if (permutation[0] == '0'){
    return 0;
  }
  long long int num = toInt(permutation);
  int substring;
  for (i = 0; i < 7; i++){
    substring = get_sub(num, i);
    if (substring % array[i]){
      return 0;
    }
  }
  return 1;
}

int main(int argc, char* argv[]){

  long long int sum = 0;
  char* digits = malloc(11);
  digits = "9876543210";
  int prime_array[7];
  prime_array[0] = 2;
  prime_array[1] = 3;
  prime_array[2] = 5;
  prime_array[3] = 7;
  prime_array[4] = 11;
  prime_array[5] = 13;
  prime_array[6] = 17;
  
  test_all(digits, 0, 10, prime_array);

  return 0;
}
