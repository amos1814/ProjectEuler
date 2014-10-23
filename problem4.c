#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

const int max = 999 * 999;

// Is the number a product of two three digit numbers?
int threeDigitProduct(int n){
  int i;
  for (i = 100; i < 1000; i++){
    if ((!(n % i)) && (n/i >= 100) && (n/i <= 999))
      return 1;
  }
  return 0;
}

// reverse string
char *rev (char* str){
  char* ret = (char*) malloc (32);
  
  int i;
  for (i = 0; i < strlen(str); i++){
    ret[i] = str[strlen(str) - 1 - i];
  }
  ret[i] = '\0';
  return ret;
}

// Is the number a palindrome?
int palindrome(int n){
  char str[32];
  
  sprintf(str, "%d", n);
  if (!strcmp(str, rev(str))){
    return 1;
  }
  return 0;
}

int main(int argc, char* argv[]){
  int i;
  for (i = max; i > 0; i--){
    if (palindrome(i) && threeDigitProduct(i)){
      printf("%d\n", i);
      exit(0);
    }
  }
  return 0;
}
