#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int partition(char* a[], int l, int r);

void quickSort(char* a[], int l, int r)
{
  int j;
  
  if( l < r )
  {
   	// divide and conquer
    j = partition(a, l, r);
    quickSort(a, l, j-1);
    quickSort(a, j+1, r);
  }
	
}

int letter_score(char* string){
  int sum = 0;
  int i;
  for (i = 0; i < strlen(string); i++){
    sum += (string[i] - 'A' + 1);
  }
  return sum;
}


int partition(char* a[], int l, int r) {
  int i, j;
  char* pivot;
  char* t;
  pivot = a[l];
  i = l; j = r+1;
  
  while(1)
  {
   	do ++i; while(strcmp(a[i], pivot) <= 0 && i <= r);
   	do --j; while(strcmp(a[j], pivot) > 0);
   	if( i >= j ) break;
   	t = a[i];
    a[i] = a[j];
    a[j] = t;
  }
  t = a[l];
  a[l] = a[j];
  a[j] = t;
  return j;
}


int main(int argc, char* argv[]){
  FILE *fp;
  fp = fopen("problem22_input.txt", "r");
  
  char buf[64];
  char** names;
  // This was set after I counted
  names = malloc(5163 * sizeof(char*));
  char c;
  int buf_pos = 0;
  int name_pos = 0;
  
  long long int sum = 0;
  
  while ((c = fgetc(fp)) != EOF){
    if (c == '"' || c == ','){
      if (buf_pos > 0){
        buf[buf_pos] = '\0';
        names[name_pos] = (char*)malloc(strlen(buf) + 1);
        strcpy(names[name_pos], buf);
        name_pos++;
      }
      buf_pos = 0;
    } else {
      buf[buf_pos] = c;
      buf_pos++;
    }

  }
  
  quickSort(names, 0, 5162);
  
  int i;
  
//  printf("%d\n", name_pos);
//  for (i = 0; i < 5163; i++){
//    printf("%s\n", names[i]);
//  }
  
  for (i = 0; i < 5163; i++){
    sum += (i+1) * letter_score(names[i]);
  }
  
  printf("%lld\n", sum);
  
  fclose(fp);
  return 0;
}
