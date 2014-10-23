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

int num_digits(int n){
  int i;
  float f = (float) n;
  for (i = 0; f >= 1; i++){
    f = f/10;
  }
  return i;
}

// return 0 if we cannot truncate
int truncate_right (int n){
  int least_digit;
  if (n < 10){
    return 0;
  }
  else {
    least_digit = n % 10;
    return (n - least_digit) / 10;
  }
}

int truncate_left (int n){
  if (n < 10){
    return 0;
  }
  int place = pow(10, num_digits(n) - 1);
  int digit = floor(n / place);
  return n - digit * place;
}

int truncatable_right(int n){
  if (n < 10){
    return 0;
  }
  int temp = n;
  while (temp != 0){
    if (!isPrime(temp)){
      return 0;
    }
    temp = truncate_right(temp);
  }
  return 1;
}

int truncatable_left(int n){
  if (n < 10){
    return 0;
  }
  int temp = n;
  while (temp != 0){
    if (!isPrime(temp)){
      return 0;
    }
    temp = truncate_left(temp);
  }
  return 1;
}

int main(int argc, char* argv[]){
  int counter = 0;
  int sum = 0;
  int i;
  for (i = 10; counter < 11; i++){
    if (!(i % 10000)){
      printf("%d\n", i);
    }
    if (!(i % 2) || !(i % 3) || !(i % 5) || !(i % 7)){
      continue;
    }
    if (truncatable_right(i) && truncatable_left(i)){
      printf("%d\n", i);
      counter++;
      sum += i;
    }
  }
  printf("sum: %d\n", sum);
  return 0;
}
