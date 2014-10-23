#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void reverse(char *reversed, char *string)
{
  int i;
  int len = strlen(string);
  
  for (i = 0; i < len; i++)
  {
    reversed[i] = string[len - i - 1];
  }
  reversed[len] = '\0';
}

int palindrome(char *str){
  char* reversed = malloc(strlen(str) + 1);
  reverse(reversed, str);
  //printf("%s, %s\n", str, reversed);
  return !strcmp(reversed, str);
}

char* toString(int n){
  char* result = malloc(10);
  sprintf(result, "%d", n);
  return result;
}

char* toBinaryString(int n){
  int i;
  char* result = malloc(33);
  for (i = 32; i >=0; i--){
    if ((n >> i) & 1){
      result[31 - i] = '1';
    }
    else {
      result[31 - i] = '0';
    }
  }
  result[32] = '\0';
  return result;
}

char* remove_zeroes(char* string){
  char* point = string;
  while(point[0] != '1'){
    point++;
  }
  return point;
}

int main(int argc, char* argv[]){
  int i;
  int sum = 0;
  for (i = 1; i < 1000000; i++){
    if (palindrome(toString(i)) && palindrome(remove_zeroes(toBinaryString(i)))){
      sum += i;
      printf("%d\n", i);
    }
  }
  printf("sum: %d\n", sum);
  return 0;
}
