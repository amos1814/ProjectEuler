#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[]){
  char* array[100];
  
  FILE *fp;
  
  fp = fopen("problem13_input.txt", "r");
    
  char buffer[64];
  char* entry;
  int index = 0;
  while (fgets(buffer, 64, fp)){
    entry = (char*)malloc(51);
    memcpy(entry, buffer, 50);
    entry[50] = '\0';
    array[index] = entry;
    index++;
  }
  
//  int i;
//  for (i = 0; i < 100; i++){
//    printf("%s\n", array[i]);
//  }
//
  
  char result[51];
  int pos;
  int num;
  int carry = 0;
  int stay;
  
  int sum;
  
  for (pos = 0; pos < 50; pos++){
    sum = 0;
    for (num = 0; num < 100; num++){
      sum += (array[num][49 - pos] - '0');
    }
    sum += carry;
    stay = (sum % 10);
    printf("%d %c\n", sum, stay + '0');
    result[49 - pos] = stay + '0';
    carry = (sum - stay) / 10;
  }
  result[50] = '0';
  
  printf("%d%s\n", carry, result);
  
  fclose(fp);
  return 0;
}
