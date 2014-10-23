#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){
  int result[200];
  int carry;
  int digit;
  int mult;
  
  int sum = 0;
  
  int dig, num;
  
  for (dig = 0; dig < 200; dig++){
    result[dig] = 0;
  }
  result[0] = 1;
  
  for (num = 1; num <= 100; num++){
    carry = 0;
    for (dig = 0; dig < 200; dig++){
      mult = result[dig] * num + carry;
      digit = mult % 10;
      result[dig] = digit;
      if (mult > 9)
        carry = (mult - digit)/10;
      else carry = 0;
    }
  }
  for (dig = 199; dig >= 0; dig--){
    printf("%d", result[dig]);
    sum += result[dig];
  }
  printf("\n%d\n", sum);
  return 0;
}
