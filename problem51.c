#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int isPrime(int n){
  int i;
  // printf("%lld \n", n);
  if (n < 2){
    return 0;
  }
  for (i = 2; i < n; i++){
    if ((n % i) == 0){
      //printf("found factor\n");
      return 0;
    }
  }
  return 1;
}

int toInt(char* string){
  int len = strlen(string);
  int pow10 = 1;
  int i;
  int sum = 0;
  for (i = 0; i < len; i++){
    sum += (string[len - i - 1] - '0') * pow10;
    pow10 *= 10;
  }
  return sum;
}

char* toString(int n){
  char* result = malloc(10);
  sprintf(result, "%d", n);
  return result;
}

int next_binary(int* binary, int size){
  
  int i;
  
//  for (i = 0; i < size; i ++){
//    printf("%d", binary[i]);
//  }
//  printf("\n");
  
  int carry = 0;
  int sum;
  for (i = 0; i < size; i++){
    sum = binary[i] + carry + 1;
    binary[i] = sum % 2;
    if (sum > 1){
      carry = 1;
    } else {
      carry = 0;
    }
  }
  // printf("%d %d\n", i, carry);
  if (carry == 1 && i == size){
    return 0;
  }
  return 1;
}

// Binary array should have same size as string.
void replace(char* string, int* binary, char c){
  int len = strlen(string);
  int i;
  for (i = 0; i < len; i++){
    if (binary[i]){
      string[i] = c;
    }
  }
}

int family_size(char* string, int* binary){
  int i, j;
  int counter = 0;
  int start = 0;
  // Can't replace most significant digit with 0
  if (binary[strlen(string) - 1] == 0){
    start = 1;
  }
  for (i = 9; i >= start; i--){
    replace (string, binary, i + '0');
    printf("%s ", string);
    
    printf("binary:");
    for (j = 0; j < strlen(string); j++){
      printf("%d", binary[j]);
    }
    printf("\n");
    
    
    if (isPrime(toInt(string))){
      counter += 1;
      if (counter == 8){
        printf("%d\n", toInt(string));
      }
    }
  }
  return counter;
}

int main(int argc, char* argv[]){
  int i, j;
  int count = 0;
  char* string;
  int* binary = calloc(sizeof(int), 10);
  for (i = 10; count < 8; i++){
    count = 0;
    string = toString(i);
    
    // Zero binary array
    for (j = 0; j < strlen(string); j++){
      binary[j] = 0;
    }
    binary[0] = 1;

    
    printf("i: %d\n", i);
    
    while(next_binary (binary, strlen(string))){
      printf("family size:%d\n",family_size(string, binary));
      fflush(stdout);
      if (family_size(string, binary) >= 8){
        exit(0);
      }
      // printf("%d\n", binary == NULL);
    }
  }
  return 0;
}
