#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){
  // Larger than we need, but OK
  short int array[1000];
  int i;
  for (i=0; i < 1000; i++){
    array[i] = 0;
  }
  
  array[0] = 1;
  
  int power;
  int digit;
  
  short twice;
  short stay;
  short carry;
  
  for (power = 1; power <= 1000; power++){
    carry = 0;
    for (digit = 0; digit < 1000; digit++){
      twice = array[digit] * 2 + carry;
      if (twice > 9){
        carry = 1;
      } else {
        carry = 0;
      }
      stay = twice % 10;
      array[digit] = stay;
    }
  }
  int sum = 0;
  for (i = 0; i < 1000; i++){
    sum += array[i];
  }
  printf("%d\n", sum);
  return 0;
}
