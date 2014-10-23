#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int word_value(char* string){
  int len = strlen(string);
  int i;
  int sum = 0;
  for (i = 0; i < len; i++){
    sum += (string[i] - 'A' + 1);
  }
  return sum;
}

int triangle(char* string){
  int target = word_value(string);
  int n;
  int triangle = 0;
  for (n = 1; triangle <= target; n++){
    triangle = (n * (n+1)) / 2;
    // printf ("%d %d\n", target, triangle);
    if (triangle == target){
      return 1;
    }
  }
  return 0;
}

int main(int argc, char* argv[]){
  int sum = 0;
  FILE *fp;
  fp = fopen("problem42_input.txt", "r");
  char buf[64];
  char c;
  int buf_pos = 0;
  
  while  ((c = fgetc(fp))!= EOF){
    if (c == '"' || c == ','){
      if (buf_pos > 0){
        buf[buf_pos] = '\0';
        // printf("%s\n", buf);
        sum += triangle(buf);
      }
      buf_pos = 0;
    } else {
      buf[buf_pos] = c;
      buf_pos++;
    }
  }
  printf("%d\n", sum);
  return 0;
}
