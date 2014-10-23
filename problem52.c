#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

// Makes a tally of digits for a number
// puts it in an array of size 10
void digits(int n, int* array){
  int len = num_digits(n);
  int i;
  for (i = 0; i < 10; i++){
    array[i] = 0;
  }
  for (i = 0; i < len; i++){
    array[nthdigit(n, i)] ++;
  }
}

void show(int* array){
  int i;
  for (i = 0; i < 10; i++){
    printf("%d", array[i]);
  }
  printf("\n");
}

// 1 if same, 0 if different
int same(int* array1, int* array2){
  int i;
  for (i = 0; i < 10; i++){
    if (array1[i] != array2[i]){
      return 0;
    }
  }
  return 1;
}

int main(int argc, char* argv[]){
  int num;
  int* arrays[6];
  int multiple;
  for (multiple = 0; multiple < 6; multiple++){
    arrays[multiple] = calloc(sizeof(int), 10);
  }
  
  multiple = 1;
  
  for (num = 10; multiple < 5; num++){
    digits(num, arrays[0]);
    
    for (multiple = 1; multiple < 6; multiple++){
      digits((multiple + 1) * num, arrays[multiple]);
      // printf("** %d %d **\n", multiple + 1, (multiple + 1) * num);
      // show(arrays[multiple]);
      if (!same(arrays[multiple], arrays[0])){
        break;
      }
    }
  }
  
  int i;
  for (i = 1; i <=6; i++){
    //printf("%d:\n", num - 1);
    printf("%dx %d\n", i, i * (num - 1));
    show(arrays[i - 1]);
  }
  
//  int* test = calloc(sizeof(int), 10);
//  
//  printf("\n EXPECTED: \n");
//  digits(2 * 142858, test);
//  show(test);
//  
//  digits(3 * 142858, test);
//  show(test);
//  
//  digits(4 * 142858, test);
//  show(test);
//  
//  digits(5 * 142858, test);
//  show(test);
//  
//  digits(6 * 142858, test);
//  show(test);
  
  
  return 0;
}
