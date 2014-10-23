#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int sum(int *array){
  return array[0] + 2*array[1] + 5*array[2] + 10*array[3] + 20*array[4] + 50*array[5] + 100*array[6];
}

int main(int argc, char* argv[]){
  int one;
  int two;
  int five;
  int ten;
  int twenty;
  int fifty;
  int hundred;
  
  // Count one two pound note
  int counter = 1;
  
  int* array = calloc(sizeof(int), 8);
  for (one = 0; one <= 200; one++){
    for (two = 0; two <= 100; two++){
      for (five = 0; five <= 40; five++){
        for (ten = 0; ten <= 20; ten++){
          for (twenty = 0; twenty <= 10; twenty++){
            for (fifty = 0; fifty <= 4; fifty++){
              for (hundred = 0; hundred <= 2; hundred++){
                array[0] = one;
                array[1] = two;
                array[2] = five;
                array[3] = ten;
                array[4] = twenty;
                array[5] = fifty;
                array[6] = hundred;
                if (sum(array) == 200)
                  counter++;
              }
            }
          }
        }
      }
    }
  }
  printf("%d\n", counter);
  
  return 0;
}
