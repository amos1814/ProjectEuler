#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){
  int array[30];
  
  //one
  array[0] = 3 * 191;
  //two
  array[1] = 3 * 190;
  //three
  array[2] = 5 * 190;
  //four
  array[3] = 4 * 190;
  //five
  array[4] = 4 * 190;
  //six
  array[5] = 3 * 190;
  //seven
  array[6] = 5 * 190;
  //eight
  array[7] = 5 * 190;
  //nine
  array[8] = 4 * 190;
  //ten
  array[9] = 3 * 10;
  //eleven
  array[10] = 6 * 10;
  //twelve
  array[11] = 6 * 10;
  //thirteen
  array[12] = 8 * 10;
  //fourteen
  array[13] = 8 * 10;
  //fifteen
  array[14] = 7 * 10;
  //sixteen
  array[15] = 7 * 10;
  //seventeen
  array[16] = 9 * 10;
  //eighteen
  array[17] = 8 * 10;
  //nineteen
  array[18] = 8 * 10;
  //twenty
  array[19] = 6 * 100;
  //thirty
  array[20] = 6 * 100;
  //forty
  array[21] = 5 * 100;
  //fifty
  array[22] = 5 * 100;
  //sixty
  array[23] = 5 * 100;
  //seventy
  array[24] = 7 * 100;
  //eighty
  array[25] = 6 * 100;
  //ninety
  array[26] = 6 * 100;
  //hundred
  array[27] = 7 * 900;
  //thousand
  array[28] = 8 * 1;
  //and 
  array[29] = 3 * 9 * 99;
  
  int i;
  int sum = 0;
  for (i = 0; i < 30; i++){
    sum += array[i];
  }
  
  printf("%d\n", sum);
  
  return 0;
}
