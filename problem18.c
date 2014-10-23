#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int max(int *array[15], int* best[15], int row, int index){
  if (best[row][index] == 0){
    if (row == 14){
      best[row][index] = array[row][index];
    } else if (max(array, best, row + 1, index) >
               max(array, best, row + 1,index + 1)){
      best[row][index] = array[row][index] + best[row + 1][index];
    } else {
      best[row][index] = array[row][index] + best[row + 1][index + 1];
    }
  }
  return best[row][index];
}

int main(int argc, char* argv[]){
  FILE *fp = fopen("problem18_input.txt", "r");
  
  int* array[15];
  
  int i, j;
  int* best[15];
  for (i=0; i < 15; i++){
    best[i] = (int*)calloc(i + 1, sizeof(int));
  }
  
  char buf[256];
  
  int index = 0;
  
  int* row;
  int pos;
  
  char* token;
  
  while (fgets(buf, sizeof(buf), fp) != NULL){
    row = (int*) malloc((index + 1) * sizeof(int));
    token = strtok(buf, " ");
    pos = 0;
    while (token != NULL){
      row[pos] = atoi(token);
      token = strtok(NULL, " ");
      pos++;
    }
    array[index] = row;
    index++;
  }

  
//  for (i = 0; i < 15 ; i++){
//    for (j = 0; j < i; j++){
//      printf("%d ", array[i][j]);
//    }
//    printf("\n");
//  }
  int result = max(array, best, 0, 0);
  
  printf("%d\n", result);
  
  return 0;
}
