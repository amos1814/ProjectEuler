#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


char* toString(int n){
  char* result = malloc(10);
  sprintf(result, "%d", n);
  return result;
}

char* intcat(char* s, int n){
  char* result = malloc(20);
  strcpy(result, s);
  strcat(result, toString(n));
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

int pandigital(char* intstring){
  int len = strlen(intstring);
  if (len != 9){
    return 0;
  }
  int i, j;
  for (i = 0; i < len; i++){
    if (intstring[i] == '0'){
      return 0;
    }
  }
  for (i = 0; i < len - 1; i++){
    for (j = i + 1; j < len; j++){
      if (intstring[i] == intstring[j]){
        return 0;
      }
    }
  }
  return 1;
}

int main(int argc, char* argv[]){
  int n;
  int try;
  char* concat;
  int max = 0;
  int current;
  // 1 * 9999 has 4 digits and 2 * 9999 has 5 digits
  for (try = 192; try < 9999; try++){
    concat = toString(try);
    for (n = 2; strlen(concat) < 10; n++){
      concat = intcat(concat, n * try);
      if (pandigital(concat)){
        current = toInt(concat);
        if (current > max){
          max = current;
        }
      }
    }
  }
  printf("%d\n", max);
  return 0;
}
