#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int num_digits(int n){
  int i;
  float f = (float) n;
  for (i = 0; f >= 1; i++){
    f = f/10;
  }
  return i;
}

int nthdigit(int x, int n)
{
  while (n--) {
    x /= 10;
  }
  return (x % 10);
}

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

int isPrime(int n){
  int i;
  // printf("%lld \n", n);
  if (n < 2 || !(n % 2)){
    return 0;
  }
  int max = floor(sqrt(n));
  for (i = 2; i < max; i++){
    if ((n % i) == 0){
      //printf("found factor\n");
      return 0;
    }
  }
  return 1;
}

int nextPrime(int prime){
  int i;
  for (i = prime + 1; ; i++){
    if (isPrime(i)){
      return i;
    }
  }
  return 0;
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

int partition(char* a[], int l, int r);

void quickSort(char* a[], int l, int r)
{
  int j;
  
  if( l < r )
  {
   	// divide and conquer
    j = partition(a, l, r);
    quickSort(a, l, j-1);
    quickSort(a, j+1, r);
  }
	
}

int partition(char* a[], int l, int r) {
  int i, j;
  char* pivot;
  char* t;
  pivot = a[l];
  i = l; j = r+1;
  
  while(1)
  {
   	do ++i; while(strcmp(a[i], pivot) <= 0 && i <= r);
   	do --j; while(strcmp(a[j], pivot) > 0);
   	if( i >= j ) break;
   	t = a[i];
    a[i] = a[j];
    a[j] = t;
  }
  t = a[l];
  a[l] = a[j];
  a[j] = t;
  return j;
}

