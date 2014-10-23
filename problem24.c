#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* First did the calculation using this reasoning:
 9! 2 725760 2
 8! 6 967680 7
 7! 6 997920 8
 6! 2 999360 3
 5! 5 999960 9
 4! 1 999984 1
 3! 2 999996 5
 2! 1 999998 4
 1! 1 999999 6
 0! 1 1000000 0
 
 */

int get_nth_remaining(int digits_remaining[10], int n){
  int i;
  int counter = 0;
  for (i = 0; i < 10; i++){
    counter += digits_remaining[i];
    if (counter == n + 1)
      break;
  }
  return i;
}

int factorial(int n)
{
  if (n == 1)
    return 1;
  else
    return n * factorial(n - 1);
}

int main(int argc, char* argv[]){
  int i;
  int digit;
  int result;
  
  int target = 1000000;
  int remaining = target;
  
  int digits_used[10];

  int digits_remaining[10];
  for(i = 0; i < 10; i++){
    digits_remaining[i] = 1;
  }

  
  for (i = 0; i < 10; i++){
    if (i == 9){
      digits_used[i] = get_nth_remaining(digits_remaining, 0);
    } else {
      for (digit = 0; digit < 11 - i; digit++){
        // printf("test %d\n", digit);
        fflush(stdout);
        if (digit * factorial(9 - i) >= remaining){
          result = get_nth_remaining(digits_remaining, digit - 1);
          digits_used[i] = result;
          remaining -= (digit - 1) * factorial(9 - i);
          printf("%d %d %d %d %d\n", 9 - i, factorial(9 - i), result, remaining, target - remaining);
          digits_remaining[result] = 0;
          break;
        }
      }
    }
  }
  for (i = 0; i < 10; i++){
    printf("%d", digits_used[i]);
  }
  printf("\n");

  return 0;
}
