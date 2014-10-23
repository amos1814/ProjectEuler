#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// add two arrays of same size
void add_large(short* dest, short *a1, short *a2, int size){
  short carry = 0;
  short stay;
  short sum;
  int i;
  for (i = 0; i < size; i++){
    sum = a1[i] + a2[i] + carry;
    if (sum > 9)
      carry = 1;
    else
      carry = 0;
    stay = sum % 10;
    dest[i] = stay;
  }
}

void show_large(short* array, int size){
  int i;
  for (i = size - 1; i >= 0; i--){
    printf("%d", array[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[]){
  int counter;
  short* prev1 = calloc(sizeof(short), 1000);
  short* prev2 = calloc(sizeof(short), 1000);
  short* current = calloc(sizeof(short), 1000);
  
  prev1[0] = 1;
  prev2[0] = 1;
  current[0] = 2;
  
  for (counter = 3; ; counter++){
    if (current[999] == 1)
      break;
    printf("%d ", counter);
    //show_large(current, 1000);
    memcpy(prev1, prev2, 2000);
    memcpy(prev2, current, 2000);
    add_large(current, prev1, prev2, 1000);
  }
  printf("%d\n",counter);
  return 0;
}
